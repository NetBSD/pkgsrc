$NetBSD: patch-apps_app__voicemail.c,v 1.3 2024/10/21 04:53:15 jnemeth Exp $

--- apps/app_voicemail.c.orig	2024-10-17 16:03:29.000000000 +0000
+++ apps/app_voicemail.c
@@ -5256,7 +5256,7 @@ static void prep_email_sub_vars(struct a
 	struct ast_config *msg_cfg;
 	const char *origcallerid, *origtime;
 	char origcidname[80], origcidnum[80], origdate[80];
-	int inttime;
+	time_t inttime;
 	struct ast_flags config_flags = { CONFIG_FLAG_NOCACHE };
 
 	/* Prepare variables for substitution in email body and subject */
@@ -5622,7 +5622,7 @@ static void make_email_file(FILE *p,
 		}
 		fprintf(p, "X-Asterisk-VM-Message-Type: %s" ENDL, msgnum > -1 ? "Message" : greeting_attachment);
 		fprintf(p, "X-Asterisk-VM-Orig-date: %s" ENDL, date);
-		fprintf(p, "X-Asterisk-VM-Orig-time: %ld" ENDL, (long) time(NULL));
+		fprintf(p, "X-Asterisk-VM-Orig-time: %jd" ENDL, (intmax_t) time(NULL));
 		fprintf(p, "X-Asterisk-VM-Message-ID: %s" ENDL, msg_id);
 	}
 	if (!ast_strlen_zero(cidnum)) {
@@ -5677,7 +5677,7 @@ static void make_email_file(FILE *p,
 			/* Forwarded type */
 			struct ast_config *msg_cfg;
 			const char *v;
-			int inttime;
+			time_t inttime;
 			char fromdir[256], fromfile[256], origdate[80] = "", origcallerid[80] = "";
 			struct ast_flags config_flags = { CONFIG_FLAG_NOCACHE };
 			/* Retrieve info from VM attribute file */
@@ -6671,7 +6671,7 @@ static void generate_msg_id(char *dst)
 	 * but only in single system solutions.
 	 */
 	unsigned int unique_counter = ast_atomic_fetchadd_int(&msg_id_incrementor, +1);
-	snprintf(dst, MSG_ID_LEN, "%ld-%08x", (long) time(NULL), unique_counter);
+	snprintf(dst, MSG_ID_LEN, "%jd-%08x", (intmax_t) time(NULL), unique_counter);
 }
 
 /*!
@@ -6792,7 +6792,7 @@ static int msg_create_from_file(struct a
 			"callerchan=%s\n"
 			"callerid=%s\n"
 			"origdate=%s\n"
-			"origtime=%ld\n"
+			"origtime=%jd\n"
 			"category=%s\n"
 			"msg_id=%s\n"
 			"flag=\n" /* flags not supported in copy from file yet */
@@ -6805,7 +6805,7 @@ static int msg_create_from_file(struct a
 			recdata->call_priority,
 			S_OR(recdata->call_callerchan, "Unknown"),
 			S_OR(recdata->call_callerid, "Unknown"),
-			date, (long) time(NULL),
+			date, (intmax_t) time(NULL),
 			S_OR(category, ""),
 			msg_id,
 			duration);
@@ -7371,7 +7371,7 @@ static int leave_voicemail(struct ast_ch
 		/* Store information in real-time storage */
 		if (ast_check_realtime("voicemail_data")) {
 			snprintf(priority, sizeof(priority), "%d", ast_channel_priority(chan));
-			snprintf(origtime, sizeof(origtime), "%ld", (long) time(NULL));
+			snprintf(origtime, sizeof(origtime), "%jd", (intmax_t) time(NULL));
 			get_date(date, sizeof(date));
 			ast_callerid_merge(callerid, sizeof(callerid),
 				S_COR(ast_channel_caller(chan)->id.name.valid, ast_channel_caller(chan)->id.name.str, NULL),
@@ -7415,7 +7415,7 @@ static int leave_voicemail(struct ast_ch
 				"callerchan=%s\n"
 				"callerid=%s\n"
 				"origdate=%s\n"
-				"origtime=%ld\n"
+				"origtime=%jd\n"
 				"category=%s\n"
 				"msg_id=%s\n",
 				ext,
@@ -12454,7 +12454,7 @@ static int vm_execmain(struct ast_channe
 				play_auto = 1;
 				if (!ast_strlen_zero(opts[OPT_ARG_PLAYFOLDER])) {
 					/* See if it is a folder name first */
-					if (isdigit(opts[OPT_ARG_PLAYFOLDER][0])) {
+					if (isdigit((unsigned char)opts[OPT_ARG_PLAYFOLDER][0])) {
 						if (sscanf(opts[OPT_ARG_PLAYFOLDER], "%30d", &play_folder) != 1) {
 							play_folder = -1;
 						}
