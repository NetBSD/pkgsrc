$NetBSD: patch-API.xs,v 1.2 2015/04/27 06:05:02 mef Exp $

Modification to be built with Perl 5.14 API.

--- API.xs.orig	2000-10-06 04:47:27.000000000 +0900
+++ API.xs	2015-02-08 22:52:28.000000000 +0900
@@ -195,7 +195,7 @@ avref2charptrptr(SV *avref)
    for (ix_av = 0;ix_av <= avref_arraylen;ix_av++)
    {
       current_val = av_fetch((AV *)SvRV(avref),ix_av,0);
-      tmp_cpp[ix_av] = StrDup(SvPV(*current_val,na));
+      tmp_cpp[ix_av] = StrDup(SvPV(*current_val,PL_na));
    }
    tmp_cpp[ix_av] = NULL;
 
@@ -226,7 +226,7 @@ avref2berptrptr(SV *avref)
       New(1,tmp_ber[ix_av],1,struct berval);
       current_val = av_fetch((AV *)SvRV(avref),ix_av,0);
 
-      tmp_char = SvPV(*current_val,na);
+      tmp_char = SvPV(*current_val,PL_na);
       val_len = SvCUR(*current_val);
 
       Newz(1,tmp2,val_len+1,char);
@@ -368,7 +368,7 @@ parse1mod(SV *ldap_value_ref,char *ldap_
    } else {
       if (cont)
          return NULL;
-      if (strcmp(SvPV(ldap_value_ref,na),"") == 0)
+      if (strcmp(SvPV(ldap_value_ref,PL_na),"") == 0)
       {
          if (ldap_add_func != 1)
          {
@@ -385,7 +385,7 @@ parse1mod(SV *ldap_value_ref,char *ldap_
             ldap_current_mod->mod_op = LDAP_MOD_REPLACE;
          }
          New(1,ldap_current_mod->mod_values,2,char *);
-         ldap_current_mod->mod_values[0] = StrDup(SvPV(ldap_value_ref,na));
+         ldap_current_mod->mod_values[0] = StrDup(SvPV(ldap_value_ref,PL_na));
          ldap_current_mod->mod_values[1] = NULL;
       }
    }
@@ -1718,7 +1718,7 @@ ldap_url_parse(url)
 	      hv_store(FullHash,options_key,strlen(options_key),options,0);
 	      ldap_free_urldesc(realcomp);
 	   } else {
-	      RETVAL = &sv_undef;
+	      RETVAL = &PL_sv_undef;
 	   }
 	}
 	OUTPUT:
