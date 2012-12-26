$NetBSD: patch-kmain.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- use standard headers
- declare own functions
- move external declarations to header files
- avoid implicit int, use C89
- silence warnings about assignments in conditionals
- use a bit of const
- remove useless casts

--- kmain.c.orig	1994-07-26 09:30:35.000000000 +0000
+++ kmain.c
@@ -6,21 +6,18 @@
 /* v1.30  1994  4/16	*/
 
 #include	<stdio.h>
+#include	<stdlib.h>
+#include	<string.h>
+#include	<unistd.h>
 
 #include	"kanjicode.h"
 #include	"ackstring.h"
-
-extern unsigned int	SjisToCode(),
-			CodeToSjis(),
-			EucToCode(),
-			CodeToEuc(),
-			CodeToJis();
-
-extern unsigned char	sjischeck_h[],
-			euccheck_h[];
+#include	"misc.h"
 
 extern FILE		*FP, *FO;
 
+static int ldefauto(void);
+
 static void
 KanjiSetup( cp )
 T_KANJI	*cp;
@@ -39,7 +36,7 @@ T_KANJI	*cp;
 	cp->codetokanji=  inputmap[cp->outcode].outputexec;
 }
 
-static
+static int
 ofileopen( ofile )
 char	*ofile;
 {
@@ -58,7 +55,7 @@ char	*ofile;
 	return	TRUE;
 }
 
-static
+static int
 kanjidrv( ifile, ofile, cp )
 char	*ifile, *ofile;
 T_KANJI	*cp;
@@ -68,7 +65,7 @@ T_KANJI	*cp;
 	if( ifile ){
 		if( !(cp->flag & fDIRSKIP) && isdir( ifile ) )
 			return	SKIP;
-		if( FP= fopen( ifile, "r" ) ){
+		if( (FP= fopen( ifile, "r" )) != NULL ){
 #if HUMAN
 			cp->time= FILEDATE( fileno(FP), 0 );
 #else
@@ -123,18 +120,18 @@ T_KANJI	*cp;
 	return	TRUE;
 }
 
-static char	*_extmap[]= {
+static const char	*_extmap[]= {
 #if SHORTNAME
 			".jis", ".euc", ".sji", "/", "/", ".uji", NULL };
 #else
 			".jis", ".euc", ".sjis", "/", "/", ".ujis", NULL };
 #endif
 
-ExtToCode( name, code )
-char	*name;
+static int
+ExtToCode( char *name, int code )
 {
 	char	*ext;
-	if( ext= SearchExtPosition( name ) ){
+	if( (ext= SearchExtPosition( name )) != NULL ){
 		int	i= 0;
 		for(; _extmap[i] ; i++ ){
 			if( !StrCmpAL( ext, _extmap[i] ) )
@@ -222,7 +219,7 @@ T_KANJI	*cp;
 		cp->outcode= DEFCODE;
 }
 
-static
+static int
 setswitch( cp, p )
 T_KANJI	*cp;
 char	*p;
@@ -263,14 +260,14 @@ char	*p;
 		if( outset ){
 			cp->inpcode= cp->outcode;
 			cp->outcode= JIS;
-			if( Isdigit(p[1]) )
+			if( Isdigit((unsigned char)p[1]) )
 				SetJisMode( *++p & 15 );
 			break;
 		}
 		outset= TRUE;
 #endif
 		cp->outcode= JIS;
-		if( Isdigit(p[1]) )
+		if( Isdigit((unsigned char)p[1]) )
 			SetJisMode( *++p & 15 );
 		break;
 	case 'e':
@@ -327,8 +324,8 @@ char	*p;
 /*	_forbreak:;*/
 }
 
-main( argc, argv )
-char	**argv;
+int
+main( int argc, char **argv )
 {
 	int	err= TRUE;
 	char	*ofile= NULL;
@@ -343,7 +340,7 @@ char	**argv;
 
 #if ENVACK
 	{
-		char	*ptr= (char*)getenv( "ACK" );
+		char	*ptr= getenv( "ACK" );
 		if( ptr && *ptr == '-' )
 			setswitch( &cp, ptr+1 );
 	}
@@ -503,11 +500,11 @@ defauto()
 #endif
 
 #if LANGCHK
-static
+static int
 declang( ptr )
 char	*ptr;
 {
-	if( ptr= (char*)strchr( ptr, '.' ) ){
+	if( (ptr= strchr( ptr, '.' )) != NULL ){
 		if( !StrCmpAL( ptr, ".sjis" ) )
 			return	SJIS;
 		if( !StrCmpAL( ptr, ".euc" ) )
@@ -515,16 +512,18 @@ char	*ptr;
 	}
 	return	NONE;
 }
-ldefauto()
+
+static int
+ldefauto(void)
 {
 	int	kanji= NONE;
-	char	*ptr= (char*)getenv( "LANG" );
+	char	*ptr= getenv( "LANG" );
 	if( ptr )
 		kanji= declang( ptr );
 	if( kanji == NONE ){
 		FILE	*fp;
 		char	buf[256];
-		if( fp= fopen( "/etc/sysinfo", "r" ) ){
+		if( (fp= fopen( "/etc/sysinfo", "r" )) != NULL ){
 			for(; fgets( buf, 256, fp ) ;){
 				if( *buf == 'L' ){
 					kanji= declang( buf );
@@ -542,7 +541,7 @@ ldefauto()
 #if ENVACK
 edefauto()
 {
-	char	*ptr= (char*)getenv( "ACK" );
+	char	*ptr= getenv( "ACK" );
 	if( ptr ){
 		if( !StrCmpAL( ptr, "sjis" ) )
 			return	SJIS;
