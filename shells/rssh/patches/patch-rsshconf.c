$NetBSD: patch-rsshconf.c,v 1.1 2012/11/01 19:30:58 joerg Exp $

--- rsshconf.c.orig	2012-10-30 19:27:54.000000000 +0000
+++ rsshconf.c
@@ -78,7 +78,7 @@ const char *keywords[] = {
 	NULL
 };
 
-int log=0;
+int my_log=0;
 
 /* flag to tell config parser to stop processing config file */
 static bool got_user_config = FALSE;
@@ -132,11 +132,11 @@ int read_shell_config( ShellOptions_t *o
 	int 	status = TRUE;		/* were all the cfg lines good? */
         char 	line[CFG_LINE_LEN + 1];	/* buffer to hold region */
 
-	log = do_log;
+	my_log = do_log;
 	memset(line, 0, CFG_LINE_LEN + 1);
         cfg_file = fopen(filename, "r");
         if (!cfg_file) {
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_WARNING);
 			log_msg("config file (%s) missing, using defaults", 
 				filename);
@@ -174,7 +174,7 @@ int process_config_line( ShellOptions_t	
 		*newline = '\0';
 	else {
 		/* there is no newline - log the error and find the EOL */
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("line %d: line too long", lineno);
 		}
@@ -241,12 +241,12 @@ int process_config_line( ShellOptions_t	
 		return TRUE;
 	default:
 		/* the keyword is unknown */
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("line %d: syntax error parsing config file",
 				       	lineno);
 		}
-		if ( keywrd[0] && log )
+		if ( keywrd[0] && my_log )
 			log_msg("unknown keyword: %s", keywrd);
 		return FALSE;
 	}
@@ -330,7 +330,7 @@ int get_token( const char *str, char *bu
 	/* initialize strings and pointers */
 	memset(buf, 0, buflen);
 	if ( !(copy = strdup(str)) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("OOM error in get_token() (fatal)");
 		}
@@ -433,11 +433,11 @@ int process_allow_scp( ShellOptions_t *o
 		       const int lineno )
 {
 	if ( !eat_comment(line) ){
-		if (log) log_msg("line %d: syntax error parsing config file",
+		if (my_log) log_msg("line %d: syntax error parsing config file",
 				       	lineno);
 		return FALSE;
 	}
-	if (log){
+	if (my_log){
 		log_set_priority(LOG_INFO);
 		log_msg("allowing scp to all users");
 	}
@@ -460,11 +460,11 @@ int process_allow_sftp( ShellOptions_t *
 	int pos;
 
 	if ( !(pos = eat_comment(line)) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (my_log) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
-	if (log){
+	if (my_log){
 		log_set_priority(LOG_INFO);
 		log_msg("allowing sftp to all users");
 	}
@@ -488,11 +488,11 @@ int process_allow_cvs( ShellOptions_t *o
 	int pos;
 
 	if ( !(pos = eat_comment(line)) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (my_log) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
-	if (log){
+	if (my_log){
 		log_set_priority(LOG_INFO);
 		log_msg("allowing cvs to all users");
 	}
@@ -516,12 +516,12 @@ int process_allow_rdist( ShellOptions_t 
 	int pos;
 
 	if ( !(pos = eat_comment(line)) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (my_log) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
 	log_set_priority(LOG_INFO);
-	if (log){
+	if (my_log){
 		log_msg("allowing rdist to all users");
 		opts->shell_flags |= RSSH_ALLOW_RDIST;
 	}
@@ -544,11 +544,11 @@ int process_allow_rsync( ShellOptions_t 
 	int pos;
 
 	if ( !(pos = eat_comment(line)) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (my_log) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
-	if (log){
+	if (my_log){
 		log_set_priority(LOG_INFO);
 		log_msg("allowing rsync to all users");
 	}
@@ -573,7 +573,7 @@ int process_chroot_path( ShellOptions_t 
 	 */
 
 	if ( !(temp = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log) log_msg("fatal error: can't allocate space for chroot path");
+		if (my_log) log_msg("fatal error: can't allocate space for chroot path");
 		exit(1);
 	}
 	/* get_asgn_param() eats trailing comments, so we won't */
@@ -584,7 +584,7 @@ int process_chroot_path( ShellOptions_t 
 	
 	/* get rid of any old value for chroot path, assign new one */
 	if ( opts->chroot_path ) free(opts->chroot_path);
-	if (log){
+	if (my_log){
 		log_set_priority(LOG_INFO);
 		log_msg("chrooting all users to %s", temp);
 	}
@@ -605,7 +605,7 @@ int process_log_facility( ShellOptions_t
 	int	pos;
 
 	if ( !(temp = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("fatal error: can't allocate space for log facility");
 		}
@@ -778,17 +778,17 @@ int process_log_facility( ShellOptions_t
 
 	free(temp);
 	if ( !eat_comment(line + pos) ){
-		if (log) log_msg("line %d: syntax error parsing config file", 
+		if (my_log) log_msg("line %d: syntax error parsing config file", 
 				lineno);
 		return FALSE;
 	}
 	if ( facname ){
 		log_set_priority(LOG_INFO);
-		if (log) log_msg("setting log facility to %s", facname);
+		if (my_log) log_msg("setting log facility to %s", facname);
 		log_set_facility(fac);
 		return TRUE;
 	}
-	if (log){
+	if (my_log){
 		log_msg("line %d: unknown log facility specified", lineno);
 		log_set_facility(LOG_USER);
 	}
@@ -804,7 +804,7 @@ int process_umask( ShellOptions_t *opts,
 	int	mask;		/* umask */
 
 	if ( !(temp = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("fatal error: can't allocate space in process_umask()");
 		}
@@ -818,7 +818,7 @@ int process_umask( ShellOptions_t *opts,
 
 	/* convert the umask to a number */
 	if ( !validate_umask(temp, &mask) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_WARNING);
 			log_msg("line %d: invalid umask specified, using default 077",
 			lineno);
@@ -827,7 +827,7 @@ int process_umask( ShellOptions_t *opts,
 		free(temp);
 		return FALSE;
 	}
-	if (log){
+	if (my_log){
 		log_set_priority(LOG_INFO);
 		log_msg("setting umask to %#o", mask);
 	}
@@ -857,7 +857,7 @@ int process_user( ShellOptions_t *opts, 
 
 	/* make space for user options */
 	if ( !(temp = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log) log_msg("fatal error: can't allocate space for user options");
+		if (my_log) log_msg("fatal error: can't allocate space for user options");
 		exit(1);
 	}
 
@@ -871,7 +871,7 @@ int process_user( ShellOptions_t *opts, 
 
 	/* now process individual config bits of temp */
 	if ( !(pos = get_token(temp, user, CFG_LINE_LEN + 1, TRUE, TRUE )) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing config file, line %d", 
 					lineno);
@@ -888,12 +888,12 @@ int process_user( ShellOptions_t *opts, 
 	 * user lines we don't care about...
 	 */
 	if ( (strcmp(user, username)) ) return TRUE;
-	if (log){
+	if (my_log){
 		log_set_priority(LOG_INFO);
 		log_msg("line %d: configuring user %s", lineno, user);
 	}
 	if ( !(len = eat_colon(temp + pos)) ){
-		if (log) log_msg("syntax error parsing config file: line %d ", 
+		if (my_log) log_msg("syntax error parsing config file: line %d ", 
 				lineno);
 		return FALSE;
 	}
@@ -902,7 +902,7 @@ int process_user( ShellOptions_t *opts, 
 	/* do the umask, but validate it last, since it's non-fatal */
 	if ( !(len = get_token(temp + pos, mask, CFG_LINE_LEN + 1, 
 			       TRUE, FALSE)) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing user umask, line %d", lineno);
 		}
@@ -912,14 +912,14 @@ int process_user( ShellOptions_t *opts, 
 
 	/* do the access bits */
 	if ( !(len = eat_colon(temp + pos)) ){
-		if (log) log_msg("syntax error parsing config file: line %d ", 
+		if (my_log) log_msg("syntax error parsing config file: line %d ", 
 				lineno);
 		return FALSE;
 	}
 	pos += len;
 	if ( !(len = get_token(temp + pos, axs, CFG_LINE_LEN + 1, 
 			       TRUE, FALSE)) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing user access, line %d", lineno);
 		}
@@ -927,7 +927,7 @@ int process_user( ShellOptions_t *opts, 
 	}
 	if ( !validate_access(axs, &allow_sftp, &allow_scp, &allow_cvs,
 			      &allow_rdist, &allow_rsync) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing access bits, line %d", lineno);
 		}
@@ -939,7 +939,7 @@ int process_user( ShellOptions_t *opts, 
 	if ( !(len = eat_colon(temp + pos)) ) goto cleanup;
 	pos += len;
 	if ( !(path = (char *)malloc(CFG_LINE_LEN + 1)) ){
-		if (log) log_msg("fatal error: can't allocate space for chroot path");
+		if (my_log) log_msg("fatal error: can't allocate space for chroot path");
 		exit(1);
 	}
 	if ( !(len = get_token(temp + pos, path, CFG_LINE_LEN + 1, 
@@ -953,7 +953,7 @@ cleanup:
 	/* make sure nothing is left */
 	while ( *(temp + pos) != '\0' && isspace(*(temp + pos)) ) pos++;
 	if ( *(temp + pos) != '\0' ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing user config: line %d", lineno);
 		}
@@ -962,14 +962,14 @@ cleanup:
 
 	/* now finally validate the umask */
 	if ( !validate_umask(mask, &tmpmask) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_WARNING);
 			log_msg("line %d: invalid umask specified, using default",
 			lineno);
 		}
 		tmpmask = 077;
 	} 
-	if (log){
+	if (my_log){
 		log_set_priority(LOG_INFO);
 		log_msg("setting %s's umask to %#o", user, tmpmask);
 	}
@@ -981,27 +981,27 @@ cleanup:
 	opts->shell_flags = 0;
 	/* now set the user-specific flags */
 	if ( allow_scp ){
-		if (log) log_msg("allowing scp to user %s", user);
+		if (my_log) log_msg("allowing scp to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_SCP;
 	}
 	if ( allow_sftp ){
-		if (log) log_msg("allowing sftp to user %s", user);
+		if (my_log) log_msg("allowing sftp to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_SFTP;
 	}
 	if ( allow_cvs ){
-		if (log) log_msg("allowing cvs to user %s", user);
+		if (my_log) log_msg("allowing cvs to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_CVS;
 	}
 	if ( allow_rdist ){
-		if (log) log_msg("allowing rdist to user %s", user);
+		if (my_log) log_msg("allowing rdist to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_RDIST;
 	}
 	if ( allow_rsync ){
-		if (log) log_msg("allowing rsync to user %s", user);
+		if (my_log) log_msg("allowing rsync to user %s", user);
 		opts->shell_flags |= RSSH_ALLOW_RSYNC;
 	}
 	if ( path ){
-		if (log) log_msg("chrooting %s to %s", user, path);
+		if (my_log) log_msg("chrooting %s to %s", user, path);
 		opts->shell_flags |= RSSH_USE_CHROOT;
 	}
 	opts->chroot_path = path;
@@ -1020,7 +1020,7 @@ int get_asgn_param( const char	*line,
 
 	/* make sure '=' is next token, otherwise syntax error */
 	if ( (pos = eat_assignment(line)) <= 0 ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("error parsing config file at line %d: "
 			"assignment expected", lineno);
@@ -1029,7 +1029,7 @@ int get_asgn_param( const char	*line,
 	}
 	/* get the string parameter of the assignment */
 	if ( !(len = get_token((line + pos), buf, buflen, FALSE, FALSE)) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing config file, line %d", 
 				lineno);
@@ -1039,7 +1039,7 @@ int get_asgn_param( const char	*line,
 	pos += len;
 	/* check for ending comment */
 	if ( !eat_comment(line + pos) ){
-		if (log){
+		if (my_log){
 			log_set_priority(LOG_ERR);
 			log_msg("syntax error parsing config file at line %d", 
 				lineno);
