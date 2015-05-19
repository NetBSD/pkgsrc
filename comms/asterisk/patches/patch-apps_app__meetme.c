$NetBSD: patch-apps_app__meetme.c,v 1.2 2015/05/19 07:52:14 jnemeth Exp $

--- apps/app_meetme.c.orig	2014-12-06 17:19:39.000000000 +0000
+++ apps/app_meetme.c
@@ -4235,14 +4235,14 @@ bailoutandtrynormal:
 				"CallerIDName: %s\r\n"
 				"ConnectedLineNum: %s\r\n"
 				"ConnectedLineName: %s\r\n"
-				"Duration: %ld\r\n",
+				"Duration: %jd\r\n",
 				ast_channel_name(chan), ast_channel_uniqueid(chan), conf->confno,
 				user->user_no,
 				S_COR(ast_channel_caller(user->chan)->id.number.valid, ast_channel_caller(user->chan)->id.number.str, "<unknown>"),
 				S_COR(ast_channel_caller(user->chan)->id.name.valid, ast_channel_caller(user->chan)->id.name.str, "<unknown>"),
 				S_COR(ast_channel_connected(user->chan)->id.number.valid, ast_channel_connected(user->chan)->id.number.str, "<unknown>"),
 				S_COR(ast_channel_connected(user->chan)->id.name.valid, ast_channel_connected(user->chan)->id.name.str, "<unknown>"),
-				(long)(now.tv_sec - user->jointime));
+				(intmax_t)(now.tv_sec - user->jointime));
 		}
 
 		if (setusercount) {
@@ -5016,6 +5016,8 @@ static int user_chan_cb(void *obj, void 
 
 /*! \brief The MeetMeadmin application 
 
+RAII_DECL(struct ast_conf_user *, eject_user, ao2_cleanup);
+
   MeetMeAdmin(confno, command, caller) */
 static int admin_exec(struct ast_channel *chan, const char *data) {
 	char *params;
@@ -5097,7 +5099,7 @@ static int admin_exec(struct ast_channel
 	case 101: /* e: Eject last user*/
 	{
 		int max_no = 0;
-		RAII_VAR(struct ast_conf_user *, eject_user, NULL, ao2_cleanup);
+		RAII_VAR(struct ast_conf_user *, eject_user, NULL);
 
 		ao2_callback(cnf->usercontainer, OBJ_NODATA, user_max_cmp, &max_no);
 		eject_user = ao2_find(cnf->usercontainer, &max_no, 0);
@@ -5864,10 +5866,13 @@ static void answer_trunk_chan(struct ast
 	ast_indicate(chan, -1);
 }
 
+RAII_DECL(struct sla_station *, station, ao2_cleanup);
+RAII_DECL(struct sla_trunk_ref *, trunk_ref, ao2_cleanup);
+
 static void *run_station(void *data)
 {
-	RAII_VAR(struct sla_station *, station, NULL, ao2_cleanup);
-	RAII_VAR(struct sla_trunk_ref *, trunk_ref, NULL, ao2_cleanup);
+	RAII_VAR(struct sla_station *, station, NULL);
+	RAII_VAR(struct sla_trunk_ref *, trunk_ref, NULL);
 	struct ast_str *conf_name = ast_str_create(16);
 	struct ast_flags64 conf_flags = { 0 };
 	struct ast_conference *conf;
@@ -6028,12 +6033,14 @@ static struct sla_ringing_trunk *sla_cho
 	return ringing_trunk;
 }
 
+RAII_DECL(struct sla_trunk_ref *, s_trunk_ref, ao2_cleanup);
+
 static void sla_handle_dial_state_event(void)
 {
 	struct sla_ringing_station *ringing_station;
 
 	AST_LIST_TRAVERSE_SAFE_BEGIN(&sla.ringing_stations, ringing_station, entry) {
-		RAII_VAR(struct sla_trunk_ref *, s_trunk_ref, NULL, ao2_cleanup);
+		RAII_VAR(struct sla_trunk_ref *, s_trunk_ref, NULL);
 		struct sla_ringing_trunk *ringing_trunk = NULL;
 		struct run_station_args args;
 		enum ast_dial_result dial_res;
@@ -6246,7 +6253,7 @@ static struct sla_trunk_ref *sla_find_tr
 static int sla_check_station_delay(struct sla_station *station, 
 	struct sla_ringing_trunk *ringing_trunk)
 {
-	RAII_VAR(struct sla_trunk_ref *, trunk_ref, NULL, ao2_cleanup);
+	RAII_VAR(struct sla_trunk_ref *, trunk_ref, NULL);
 	unsigned int delay = UINT_MAX;
 	int time_left, time_elapsed;
 
@@ -6657,8 +6664,8 @@ static void *dial_trunk(void *data)
 	char conf_name[MAX_CONFNUM];
 	struct ast_conference *conf;
 	struct ast_flags64 conf_flags = { 0 };
-	RAII_VAR(struct sla_trunk_ref *, trunk_ref, args->trunk_ref, ao2_cleanup);
-	RAII_VAR(struct sla_station *, station, args->station, ao2_cleanup);
+	RAII_VAR(struct sla_trunk_ref *, trunk_ref, args->trunk_ref);
+	RAII_VAR(struct sla_station *, station, args->station);
 	int caller_is_saved;
 	struct ast_party_caller caller;
 	int last_state = 0;
@@ -6805,8 +6812,8 @@ static struct sla_trunk_ref *sla_choose_
 static int sla_station_exec(struct ast_channel *chan, const char *data)
 {
 	char *station_name, *trunk_name;
-	RAII_VAR(struct sla_station *, station, NULL, ao2_cleanup);
-	RAII_VAR(struct sla_trunk_ref *, trunk_ref, NULL, ao2_cleanup);
+	RAII_VAR(struct sla_station *, station, NULL);
+	RAII_VAR(struct sla_trunk_ref *, trunk_ref, NULL);
 	char conf_name[MAX_CONFNUM];
 	struct ast_flags64 conf_flags = { 0 };
 	struct ast_conference *conf;
@@ -7024,12 +7031,14 @@ AST_APP_OPTIONS(sla_trunk_opts, BEGIN_OP
 	AST_APP_OPTION_ARG('M', SLA_TRUNK_OPT_MOH, SLA_TRUNK_OPT_ARG_MOH_CLASS),
 END_OPTIONS );
 
+RAII_DECL(struct sla_trunk *, trunk, ao2_cleanup);
+
 static int sla_trunk_exec(struct ast_channel *chan, const char *data)
 {
 	char conf_name[MAX_CONFNUM];
 	struct ast_conference *conf;
 	struct ast_flags64 conf_flags = { 0 };
-	RAII_VAR(struct sla_trunk *, trunk, NULL, ao2_cleanup);
+	RAII_VAR(struct sla_trunk *, trunk, NULL);
 	struct sla_ringing_trunk *ringing_trunk;
 	AST_DECLARE_APP_ARGS(args,
 		AST_APP_ARG(trunk_name);
@@ -7125,7 +7134,7 @@ static int sla_trunk_exec(struct ast_cha
 static enum ast_device_state sla_state(const char *data)
 {
 	char *buf, *station_name, *trunk_name;
-	RAII_VAR(struct sla_station *, station, NULL, ao2_cleanup);
+	RAII_VAR(struct sla_station *, station, NULL);
 	struct sla_trunk_ref *trunk_ref;
 	enum ast_device_state res = AST_DEVICE_INVALID;
 
@@ -7286,7 +7295,7 @@ static void sla_trunk_destructor(void *o
 
 static int sla_build_trunk(struct ast_config *cfg, const char *cat)
 {
-	RAII_VAR(struct sla_trunk *, trunk, NULL, ao2_cleanup);
+	RAII_VAR(struct sla_trunk *, trunk, NULL);
 	struct ast_variable *var;
 	const char *dev;
 	int existing_trunk = 0;
@@ -7375,7 +7384,7 @@ static int sla_build_trunk(struct ast_co
  */
 static void sla_add_trunk_to_station(struct sla_station *station, struct ast_variable *var)
 {
-	RAII_VAR(struct sla_trunk *, trunk, NULL, ao2_cleanup);
+	RAII_VAR(struct sla_trunk *, trunk, NULL);
 	struct sla_trunk_ref *trunk_ref = NULL;
 	struct sla_station_ref *station_ref;
 	char *trunk_name, *options, *cur;
@@ -7459,7 +7468,7 @@ static void sla_add_trunk_to_station(str
 
 static int sla_build_station(struct ast_config *cfg, const char *cat)
 {
-	RAII_VAR(struct sla_station *, station, NULL, ao2_cleanup);
+	RAII_VAR(struct sla_station *, station, NULL);
 	struct ast_variable *var;
 	const char *dev;
 	int existing_station = 0;
