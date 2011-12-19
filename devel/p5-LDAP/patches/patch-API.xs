$NetBSD: patch-API.xs,v 1.1 2011/12/19 15:26:51 hiramatsu Exp $

Modification to be built with Perl 5.14 API.

--- API.xs.orig	2011-12-19 09:59:44.000000000 +0000
+++ API.xs
@@ -107,7 +107,7 @@ char ** avref2charptrptr(SV *avref)
    for (ix_av = 0;ix_av <= avref_arraylen;ix_av++)
    {
       current_val = av_fetch((AV *)SvRV(avref),ix_av,0);
-      tmp_cpp[ix_av] = strdup(SvPV(*current_val,na));
+      tmp_cpp[ix_av] = strdup(SvPV(*current_val,PL_na));
    }
    tmp_cpp[ix_av] = NULL;
 
@@ -135,7 +135,7 @@ struct berval ** avref2berptrptr(SV *avr
       New(1,tmp_ber[ix_av],1,struct berval);
       current_val = av_fetch((AV *)SvRV(avref),ix_av,0);
 
-      tmp_char = SvPV(*current_val,na);
+      tmp_char = SvPV(*current_val,PL_na);
       val_len = SvCUR(*current_val);
 
       Newz(1,tmp2,val_len+1,char);
@@ -272,7 +272,7 @@ LDAPMod *parse1mod(SV *ldap_value_ref,ch
    } else {
       if (cont)
          return NULL;
-      if (strcmp(SvPV(ldap_value_ref,na),"") == 0)
+      if (strcmp(SvPV(ldap_value_ref,PL_na),"") == 0)
       {
          if (ldap_add_func != 1)
          {
@@ -289,7 +289,7 @@ LDAPMod *parse1mod(SV *ldap_value_ref,ch
             ldap_current_mod->mod_op = LDAP_MOD_REPLACE;
          }
          New(1,ldap_current_mod->mod_values,2,char *);
-         ldap_current_mod->mod_values[0] = strdup(SvPV(ldap_value_ref,na));
+         ldap_current_mod->mod_values[0] = strdup(SvPV(ldap_value_ref,PL_na));
          ldap_current_mod->mod_values[1] = NULL;
       }
    }
@@ -1528,7 +1528,7 @@ ldap_url_parse(url)
 	      hv_store(FullHash,options_key,strlen(options_key),options,0);
 	      ldap_free_urldesc(realcomp);
 	   } else {
-	      RETVAL = &sv_undef;
+	      RETVAL = &PL_sv_undef;
 	   }
 	}
 	OUTPUT:
