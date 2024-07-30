$NetBSD: patch-opendkim_opendkim.c,v 1.2 2024/07/30 13:49:04 manu Exp $

Add OmitHeadersDB directive to specify file containing per-recipient 
list of headers to not use in signature. The file format is:

user@doamin.tld	header1,header2,header3
domain.tld	header4,header5

From upstream https://github.com/trusteddomainproject/OpenDKIM/pull/173

--- opendkim/opendkim.c.orig
+++ opendkim/opendkim.c
@@ -390,6 +390,7 @@ struct dkimf_config
 	DKIMF_DB	conf_domainsdb;		/* domains to sign (DB) */
 	DKIMF_DB	conf_omithdrdb;		/* headers to omit (DB) */
 	char **		conf_omithdrs;		/* headers to omit (array) */
+	DKIMF_DB	conf_omithdrkdb;	/* headers to omit (keyed DB) */
 	DKIMF_DB	conf_signhdrsdb;	/* headers to sign (DB) */
 	char **		conf_signhdrs;		/* headers to sign (array) */
 	DKIMF_DB	conf_senderhdrsdb;	/* sender headers (DB) */
@@ -519,6 +520,7 @@ struct msgctx
 						/* primary domain */
 	unsigned char	mctx_dkimar[DKIM_MAXHEADER + 1];
 						/* DKIM Auth-Results content */
+	char **		mctx_omithdrs;		/* headers to omit (array) */
 };
 
 /*
@@ -1053,6 +1055,188 @@ dkimf_getsymval(SMFICTX *ctx, char *sym)
 		return smfi_getsymval(ctx, sym);
 }
 
+
+/*
+**  DKIMF_GET_OMITHEADERS -- Get per-recipient headers to not sign
+**
+**  Parameters:
+**  	conf -- configuration handle
+**  	rcpt -- recipient
+**  	hdrs -- comma-separated list of headers (returned)
+**  	hdrslen -- size of hdrs buffer
+**
+**  Return value:
+**  	0 -- success
+**  	!0 -- error
+*/
+
+static int
+dkimf_get_omitheaders(struct dkimf_config *conf, const char *rcpt,
+                      char *hdrs, size_t hdrslen)
+{
+	int status;
+	_Bool found;
+	unsigned char *user = NULL;
+	unsigned char *domain = NULL;
+	char tmp[MAXADDRESS + 1];
+	char addr[MAXADDRESS + 1];
+	struct dkimf_db_data req;
+
+	assert(conf != NULL);
+	assert(conf->conf_omithdrkdb != NULL);
+	assert(rcpt != NULL);
+	assert(hdrs != NULL);
+
+	strlcpy(tmp, rcpt, sizeof(tmp));
+	status = dkim_mail_parse(tmp, &user, &domain);
+	if (status != 0 || user == NULL || domain == NULL)
+	{
+		return -1;
+	}
+
+	memset(&req, '\0', sizeof req);
+	req.dbdata_buffer = hdrs;
+	req.dbdata_buflen = hdrslen;
+
+	/* first try full "user@host" */
+	found = FALSE;
+	(void)snprintf(addr, sizeof addr, "%s@%s", user, domain);
+	status = dkimf_db_get(conf->conf_omithdrkdb, addr, strlen(addr),
+			      &req, 1, &found);
+	if (status != 0 ||
+	    (found && (req.dbdata_buflen == 0 ||
+		       req.dbdata_buflen == (size_t) -1)))
+	{
+		return -1;
+	}
+	else if (found)
+	{
+		req.dbdata_buffer[req.dbdata_buflen] = '\0';
+		return 0;
+	}
+
+	/* now just "host" */
+
+	memset(&req, '\0', sizeof req);
+	req.dbdata_buffer = hdrs;
+	req.dbdata_buflen = hdrslen;
+	
+	found = FALSE;
+	status = dkimf_db_get(conf->conf_omithdrkdb, domain, strlen(domain),
+			      &req, 1, &found);
+	if (status != 0 ||
+	    (found && (req.dbdata_buflen == 0 ||
+		       req.dbdata_buflen == (size_t) -1)))
+	{
+		return -1;
+	}
+	else if (found)
+	{
+		req.dbdata_buffer[req.dbdata_buflen] = '\0';
+		return 0;
+	}
+
+	return -1;
+}
+
+/*
+**  DKIMF_APPEND_ARRAY -- Append an item to an string array 
+**                        The item is only added if it is not
+**			  alreay present. 
+**
+**  Parameters:
+**  	arrayp -- pointer to array
+**  	item -- new string to append
+**  	init -- array of strings to insert if array is empty
+**
+**  Return value:
+**  	None
+*/
+
+static void
+dkimf_append_array(char ***arrayp, char *item, const u_char **init)
+{
+	char **array;
+	int i;
+
+	assert(arrayp != NULL);
+	assert(*arrayp != NULL || init != NULL);
+
+	array = *arrayp;
+
+	if (array == NULL) {
+		for (i = 0; init[i]; i++);
+
+		array = calloc(i + 1, sizeof(*array));
+		if (array == NULL)
+		{
+			syslog(LOG_ERR, "calloc failed");
+			return;
+		}
+
+		for (i = 0; init[i]; i++)
+			array[i] = strdup(init[i]);
+	}
+
+	for (i = 0; array[i]; i++) {
+		if (strcasecmp(array[i], item) == 0)
+			return;
+	}
+	
+	if ((array = realloc(array, (i + 2) * sizeof(*array))) == NULL)
+        {
+		syslog(LOG_ERR, "realloc failed");
+		return;
+        }
+	
+	array[i] = strdup(item);
+	array[i + 1] = NULL;
+
+	*arrayp = array;
+	
+	return;
+}
+
+/*
+**  DKIMF_CONFIGURE_OMITHEADERS -- Configure per-recipient header to not sign
+**
+**  Parameters:
+**  	conf -- configuration handle
+**  	omithdrs -- comma-separated list of headers to not sign
+**
+**  Return value:
+**  	None
+*/
+
+static void
+dkimf_configure_omitheaders(msgctx mctx, struct dkimf_config *conf,
+			    char *omithdrs)
+{
+	size_t count = 0;
+	const char *delim = " ,";
+	char *p;
+	char *last;
+
+	assert(conf != NULL);
+	assert(conf->conf_libopendkim != NULL);
+
+	if (omithdrs) {
+		for (p = strtok_r(omithdrs, delim, &last);
+		     p != NULL;
+		     p = strtok_r(NULL, delim, &last))
+			dkimf_append_array(&mctx->mctx_omithdrs, p,
+					   dkim_should_not_signhdrs);
+	}
+
+	(void)dkim_options(conf->conf_libopendkim,
+			   DKIM_OP_SETOPT,
+			   DKIM_OPTS_SKIPHDRS,
+			   mctx->mctx_omithdrs, sizeof(char **));
+
+	return;
+}
+
+
 #ifdef USE_LUA
 /*
 **  LUA ACCESSOR FUNCTIONS
@@ -5920,6 +6104,9 @@ dkimf_config_free(struct dkimf_config *conf)
 	if (conf->conf_omithdrdb != NULL)
 		dkimf_db_close(conf->conf_omithdrdb);
 
+	if (conf->conf_omithdrkdb != NULL)
+		dkimf_db_close(conf->conf_omithdrkdb);
+
 	if (conf->conf_thirdpartydb != NULL)
 		dkimf_db_close(conf->conf_thirdpartydb);
 
@@ -7293,6 +7480,29 @@ dkimf_config_load(struct config *data, struct dkimf_config *conf,
 		}
 	}
 
+	str = NULL;
+	if (data != NULL)
+	{
+		(void) config_get(data, "OmitHeadersDB", &str, sizeof str);
+		if (str != NULL)
+		{
+			int status;
+			char *dberr = NULL;
+
+			status = dkimf_db_open(&conf->conf_omithdrkdb, str,
+					       (dbflags |
+						DKIMF_DB_FLAG_ICASE |
+						DKIMF_DB_FLAG_READONLY),
+					       NULL, &dberr);
+			if (status != 0)
+			{
+				snprintf(err, errlen, "%s: dkimf_db_open(): %s",
+					 str, dberr);
+				return -1;
+			}	
+		}
+	}
+
 	str = NULL;
 	if (data != NULL)
 	{
@@ -11238,6 +11448,15 @@ mlfi_envrcpt(SMFICTX *ctx, char **envrcpt)
 		dfc->mctx_rcptlist = a;
 	}
 
+	if (conf->conf_omithdrkdb != NULL) {
+		char omithdrs[MAXBUFRSZ];
+		if (dkimf_get_omitheaders(conf, envrcpt[0],
+					  omithdrs, sizeof omithdrs) != -1)
+			dkimf_configure_omitheaders(dfc, conf, omithdrs);
+		else
+			dkimf_configure_omitheaders(dfc, conf, NULL);
+	}
+
 	return SMFIS_CONTINUE;
 }
 
