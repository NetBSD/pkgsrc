$NetBSD: patch-apps_app__confbridge.c,v 1.1 2013/08/08 00:45:10 jnemeth Exp $

--- apps/app_confbridge.c.orig	2013-03-04 20:03:09.000000000 +0000
+++ apps/app_confbridge.c
@@ -2137,10 +2137,12 @@ static char *complete_confbridge_name(co
 	return res;
 }
 
+RAII_DECL(struct conference_bridge *, bridge, ao2_cleanup);
+
 static char *complete_confbridge_participant(const char *bridge_name, const char *line, const char *word, int pos, int state)
 {
 	int which = 0;
-	RAII_VAR(struct conference_bridge *, bridge, NULL, ao2_cleanup);
+	RAII_VAR(struct conference_bridge *, bridge, NULL);
 	struct conference_bridge tmp;
 	struct conference_bridge_user *participant;
 	char *res = NULL;
