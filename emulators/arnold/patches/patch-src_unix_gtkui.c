$NetBSD: patch-src_unix_gtkui.c,v 1.1 2018/04/09 15:03:22 ryoon Exp $

--- src/unix/gtkui.c.orig	2004-01-04 05:09:30.000000000 +0000
+++ src/unix/gtkui.c
@@ -20,6 +20,17 @@
 #include <gtk/gtk.h>
 #include "../cpc/messages.h"
 
+void ConfigCPC464();
+void ConfigCPC6128();
+void ConfigCPC664();
+void Config464Plus();
+void Config6128Plus();
+void ConfigKCCompact();
+
+void SaveFile(const char *,const unsigned char *pPtr, unsigned long 
+Length);
+
+
 GtkWidget *btn_diska, *btn_diskb, *btn_cartridge, *btn_tape, *btn_loadsnap,
 	*btn_savesnap, *btn_reset, *btn_quit, *btn_lock, *btn_double,
 	*btn_audio, *btn_joysticks;
@@ -33,7 +44,8 @@ static char *CPCTYPESTRINGS[7] = { "CPC 
 	"CPC 6128+", "KC Compact", NULL };
 static char *CRTCTYPESTRINGS[6] = { "CRTC 0", "CRTC 1", "CRTC 2", "CRTC 3",
 	"CRTC 4", NULL };
-static char *KEYBOARDTYPESTRINGS[3] = { "QWERTY", "QWERTZ", "AZERTY", NULL };
+static char *KEYBOARDTYPESTRINGS[4] = { "QWERTY", "QWERTZ", "AZERTY", NULL 
+};
 
 static BOOL cpcPaused = FALSE;
 
@@ -92,12 +104,29 @@ void get_filename_and_destroy( char *fil
 
 }
 
+void write_disk(int drive)
+{
+	unsigned char *pBuffer;
+	unsigned long Length;
+
+	Length = DiskImage_CalculateOutputSize(drive);
+		
+	pBuffer = malloc(Length);
+	if (pBuffer)
+	{
+		DiskImage_GenerateOutputData(pBuffer, drive);
+		SaveFile("test.dsk",pBuffer,Length);
+
+		free(pBuffer);	
+	}	
+}
+
 
 void save_disk_and_insert( GtkWidget *w, GtkWindow *dialog, int drive,
 	char *filename){
 	gtk_widget_destroy(GTK_WIDGET(dialog));
 
-	DiskImage_WriteImage(drive);
+	write_disk(drive);
 	DiskImage_RemoveDisk(drive);
 	
 	if (!GenericInterface_InsertDiskImage( drive, filename )) {
@@ -109,7 +138,7 @@ void dont_save_disk_and_insert( GtkWidge
 	char *filename) {
 	gtk_widget_destroy(GTK_WIDGET(dialog));
 
-	DiskImage_RemoveDisk(drive);
+	write_disk(drive);
 
 	if (!GenericInterface_InsertDiskImage( drive, filename )) {
 		printf("Failed to open disk image %s.\r\n", filename);
@@ -135,7 +164,7 @@ void dont_save_diskB_and_insert( GtkWidg
 void save_disk_and_quit( GtkWidget *w, GtkWindow *dialog, int drive) {
 	gtk_widget_destroy(GTK_WIDGET(dialog));
 
-	DiskImage_WriteImage(drive);
+	write_disk(drive);
 	DiskImage_RemoveDisk(drive);
 
 	if (!FDD_IsDiskPresent(0) && !FDD_IsDiskPresent(1)) {
@@ -146,7 +175,7 @@ void save_disk_and_quit( GtkWidget *w, G
 void dont_save_disk_and_quit( GtkWidget *w, GtkWindow *dialog, int drive){
 	gtk_widget_destroy(GTK_WIDGET(dialog));
 
-	DiskImage_RemoveDisk(drive);
+	write_disk(drive);
 
 	if (!FDD_IsDiskPresent(0) && !FDD_IsDiskPresent(1)) {
 		gtk_main_quit();
@@ -237,7 +266,7 @@ void choosen_tape( GtkWidget *w, GtkFile
 	char filename[ PATH_MAX ];
 	get_filename_and_destroy( filename, fs );
 
-	if (!GenericInterface_InsertTapeImage( filename )) {
+	if (!GenericInterface_InsertTape( filename )) {
 		printf(Messages[73], filename);
 	} 
 
@@ -258,15 +287,19 @@ void choosen_savesnap( GtkWidget *w, Gtk
 
 	char filename[ PATH_MAX ];
 	int cpcType;
+	int nSize = 64;
 	get_filename_and_destroy( filename, fs );
 
-	cpcType = CPC_GetCPCType();
-	if (cpcType == CPC_TYPE_CPC6128 || cpcType == CPC_TYPE_6128PLUS) {
-		GenericInterface_SetSnapshotSize(128);
-	} else {
-		GenericInterface_SetSnapshotSize(64);
-	}
-	if (!GenericInterface_SnapshotSave( filename )) {
+//	cpcType = CPC_GetHardware();
+//
+//	if (cpcType == CPC_TYPE_CPC6128 || cpcType == CPC_TYPE_6128PLUS) {
+//		nSize = 128;
+//	} else {
+//		nSize = 64;
+//	}
+
+	nSize = 128;
+	if (!GenericInterface_SnapshotSave( filename,3,nSize )) {
 		printf(Messages[90], filename);
 	} 
 	cpcPaused = FALSE;
@@ -318,7 +351,7 @@ void choose_media( GtkWidget *widget, gp
 }
 
 void reset( GtkWidget *widget, gpointer data ) {
-	GenericInterface_DoReset();
+	CPC_Reset();
 }
 
 static void quit( GtkWidget *widget, gpointer data ) {
@@ -393,7 +426,47 @@ int indexInArray( char *s, char **p ) {
 void choose_cpctype( GtkWidget *widget, gpointer data ) {
 	fprintf(stderr, Messages[96], (char *) data,
 		indexInArray((char *) data, CPCTYPESTRINGS));
-	CPC_SetCPCType( indexInArray((char *) data, CPCTYPESTRINGS ));
+
+	switch (indexInArray((char *)data, CPCTYPESTRINGS))
+	{
+		case 0:
+		{
+			ConfigCPC464();
+		}
+		break;
+
+		case 1:
+		{
+			ConfigCPC664();
+		}
+		break;
+
+		case 2:
+		{
+			ConfigCPC6128();
+		}
+		break;
+
+		case 3:
+		{
+			Config464Plus();
+		}
+		break;
+
+		case 4:
+		{
+			Config6128Plus();
+		}
+		break;
+
+		case 5:
+		{
+			ConfigKCCompact();
+		}
+		break;
+	}
+
+//	CPC_SetCPCType( indexInArray((char *) data, CPCTYPESTRINGS ));
 }
 
 void choose_crtctype( GtkWidget *widget, gpointer data ) {
