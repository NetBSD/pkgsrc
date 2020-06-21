$NetBSD: patch-ntpd_ntp__config.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/ntp_config.c.orig	2020-03-04 01:38:14.000000000 +0000
+++ ntpd/ntp_config.c
@@ -2986,7 +2986,7 @@ void
 attrtopsl(int poll, attr_val *avp)
 {
 
-	DEBUG_INSIST((poll - 3) < sizeof psl);
+	DEBUG_INSIST((size_t)(poll - 3) < sizeof psl);
 	if (poll < 3 || poll > 17) {
 		msyslog(LOG_ERR, "attrtopsl(%d, ...): Poll value is out of range - ignoring", poll);
 	} else {
@@ -3836,6 +3836,7 @@ config_fudge(
 	address_node *addr_node;
 	struct refclockstat clock_stat;
 	int err_flag;
+	size_t len;
 
 	curr_fudge = HEAD_PFIFO(ptree->fudge);
 	for (; curr_fudge != NULL; curr_fudge = curr_fudge->link) {
@@ -3889,9 +3890,13 @@ config_fudge(
 
 			case T_Refid:
 				clock_stat.haveflags |= CLK_HAVEVAL2;
-				/* strncpy() does exactly what we want here: */
-				strncpy((char*)&clock_stat.fudgeval2,
-					curr_opt->value.s, 4);
+				/* avoid using strncpy because gcc warns */
+				len = strlen(curr_opt->value.s);
+				if (len > sizeof(clock_stat.fudgeval2))
+					len = sizeof(clock_stat.fudgeval2);
+				clock_stat.fudgeval2 = 0;
+				memcpy(&clock_stat.fudgeval2,
+				    curr_opt->value.s, len);
 				break;
 
 			case T_Flag1:
@@ -4998,7 +5003,7 @@ getconfig(
 
 
 	/*** BULK OF THE PARSER ***/
-#ifdef DEBUG
+#if defined(DEBUG) && defined(YYDEBUG)
 	yydebug = !!(debug >= 5);
 #endif
 	yyparse();
@@ -5461,7 +5466,7 @@ ntp_rlimit(
 			(int)(rl_value / rl_scale), rl_sstr));
 		rl.rlim_cur = rl.rlim_max = rl_value;
 		if (setrlimit(RLIMIT_MEMLOCK, &rl) == -1)
-			msyslog(LOG_ERR, "Cannot set RLIMIT_MEMLOCK: %m");
+			msyslog(LOG_DEBUG, "Cannot set RLIMIT_MEMLOCK: %m");
 		break;
 # endif /* RLIMIT_MEMLOCK */
 
