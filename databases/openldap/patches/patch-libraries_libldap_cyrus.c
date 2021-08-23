$NetBSD: patch-libraries_libldap_cyrus.c,v 1.1 2021/08/23 09:58:58 adam Exp $

--- libraries/libldap/cyrus.c.orig	2021-07-27 17:44:47.000000000 +0000
+++ libraries/libldap/cyrus.c
@@ -767,7 +767,7 @@ ldap_int_sasl_external(
 	LDAP *ld,
 	LDAPConn *conn,
 	const char * authid,
-	ber_len_t ssf )
+	ber_uint_t ssf )
 {
 	int sc;
 	sasl_conn_t *ctx;
@@ -911,6 +911,7 @@ int ldap_pvt_sasl_secprops(
 	char **props;
 	unsigned sflags = 0;
 	int got_sflags = 0;
+	int tmp_ssf;
 	sasl_ssf_t max_ssf = 0;
 	int got_max_ssf = 0;
 	sasl_ssf_t min_ssf = 0;
@@ -941,9 +942,9 @@ int ldap_pvt_sasl_secprops(
 				if ( next == &props[i][sprops[j].key.bv_len] || next[0] != '\0' ) continue;
 				switch( sprops[j].ival ) {
 				case GOT_MINSSF:
-					min_ssf = v; got_min_ssf++; break;
+					min_ssf = (v >= 0 ? (sasl_ssf_t)v : 0); got_min_ssf++; break;
 				case GOT_MAXSSF:
-					max_ssf = v; got_max_ssf++; break;
+					max_ssf = (v >= 0 ? (sasl_ssf_t)v : 0); got_max_ssf++; break;
 				case GOT_MAXBUF:
 					maxbufsize = v; got_maxbufsize++; break;
 				}
@@ -1053,7 +1054,7 @@ ldap_int_sasl_get_option( LDAP *ld, int 
 				return -1;
 			}
 
-			*(ber_len_t *)arg = *ssf;
+			*(sasl_ssf_t *)arg = *ssf;
 		} break;
 
 		case LDAP_OPT_X_SASL_SSF_EXTERNAL:
@@ -1061,13 +1062,13 @@ ldap_int_sasl_get_option( LDAP *ld, int 
 			return -1;
 
 		case LDAP_OPT_X_SASL_SSF_MIN:
-			*(ber_len_t *)arg = ld->ld_options.ldo_sasl_secprops.min_ssf;
+			*(sasl_ssf_t *)arg = ld->ld_options.ldo_sasl_secprops.min_ssf;
 			break;
 		case LDAP_OPT_X_SASL_SSF_MAX:
-			*(ber_len_t *)arg = ld->ld_options.ldo_sasl_secprops.max_ssf;
+			*(sasl_ssf_t *)arg = ld->ld_options.ldo_sasl_secprops.max_ssf;
 			break;
 		case LDAP_OPT_X_SASL_MAXBUFSIZE:
-			*(ber_len_t *)arg = ld->ld_options.ldo_sasl_secprops.maxbufsize;
+			*(sasl_ssf_t *)arg = ld->ld_options.ldo_sasl_secprops.maxbufsize;
 			break;
 		case LDAP_OPT_X_SASL_NOCANON:
 			*(int *)arg = (int) LDAP_BOOL_GET(&ld->ld_options, LDAP_BOOL_SASL_NOCANON );
@@ -1171,7 +1172,7 @@ ldap_int_sasl_set_option( LDAP *ld, int 
 #else
 		memset(&extprops, 0L, sizeof(extprops));
 
-		extprops.ssf = * (ber_len_t *) arg;
+		extprops.ssf = * (sasl_ssf_t *) arg;
 
 		sc = sasl_setprop( ctx, SASL_SSF_EXTERNAL,
 			(void *) &extprops );
@@ -1183,13 +1184,13 @@ ldap_int_sasl_set_option( LDAP *ld, int 
 		} break;
 
 	case LDAP_OPT_X_SASL_SSF_MIN:
-		ld->ld_options.ldo_sasl_secprops.min_ssf = *(ber_len_t *)arg;
+		ld->ld_options.ldo_sasl_secprops.min_ssf = *(sasl_ssf_t *)arg;
 		break;
 	case LDAP_OPT_X_SASL_SSF_MAX:
-		ld->ld_options.ldo_sasl_secprops.max_ssf = *(ber_len_t *)arg;
+		ld->ld_options.ldo_sasl_secprops.max_ssf = *(sasl_ssf_t *)arg;
 		break;
 	case LDAP_OPT_X_SASL_MAXBUFSIZE:
-		ld->ld_options.ldo_sasl_secprops.maxbufsize = *(ber_len_t *)arg;
+		ld->ld_options.ldo_sasl_secprops.maxbufsize = *(sasl_ssf_t *)arg;
 		break;
 	case LDAP_OPT_X_SASL_NOCANON:
 		if ( arg == LDAP_OPT_OFF ) {
@@ -1329,7 +1330,7 @@ ldap_int_sasl_external(
 	LDAP *ld,
 	LDAPConn *conn,
 	const char * authid,
-	ber_len_t ssf )
+	ber_uint_t ssf )
 { return LDAP_SUCCESS; }
 
 #endif /* HAVE_CYRUS_SASL */
