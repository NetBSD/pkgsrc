$NetBSD: patch-perl.c,v 1.1.2.2 2016/04/20 19:27:05 bsiegert Exp $

CVE-2016-2381 - Perl might allow context-dependent attackers to bypass the taint
protection mechanism in a child process via duplicate environment variables in
envp.
https://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2016-2381

--- perl.c.orig	2015-10-17 12:38:38.000000000 +0000
+++ perl.c
@@ -4298,23 +4298,70 @@ S_init_postdump_symbols(pTHX_ int argc, 
 	}
 	if (env) {
 	  char *s, *old_var;
+          STRLEN nlen;
 	  SV *sv;
+          HV *dups = newHV();
+
 	  for (; *env; env++) {
 	    old_var = *env;
 
 	    if (!(s = strchr(old_var,'=')) || s == old_var)
 		continue;
+            nlen = s - old_var;
 
 #if defined(MSDOS) && !defined(DJGPP)
 	    *s = '\0';
 	    (void)strupr(old_var);
 	    *s = '=';
 #endif
-	    sv = newSVpv(s+1, 0);
-	    (void)hv_store(hv, old_var, s - old_var, sv, 0);
+            if (hv_exists(hv, old_var, nlen)) {
+                const char *name = savepvn(old_var, nlen);
+
+                /* make sure we use the same value as getenv(), otherwise code that
+                   uses getenv() (like setlocale()) might see a different value to %ENV
+                 */
+                sv = newSVpv(PerlEnv_getenv(name), 0);
+
+                /* keep a count of the dups of this name so we can de-dup environ later */
+                if (hv_exists(dups, name, nlen))
+                    ++SvIVX(*hv_fetch(dups, name, nlen, 0));
+                else
+                    (void)hv_store(dups, name, nlen, newSViv(1), 0);
+
+                Safefree(name);
+            }
+            else {
+                sv = newSVpv(s+1, 0);
+            }
+	    (void)hv_store(hv, old_var, nlen, sv, 0);
 	    if (env_is_not_environ)
 	        mg_set(sv);
 	  }
+          if (HvKEYS(dups)) {
+              /* environ has some duplicate definitions, remove them */
+              HE *entry;
+              hv_iterinit(dups);
+              while ((entry = hv_iternext_flags(dups, 0))) {
+                  STRLEN nlen;
+                  const char *name = HePV(entry, nlen);
+                  IV count = SvIV(HeVAL(entry));
+                  IV i;
+                  SV **valp = hv_fetch(hv, name, nlen, 0);
+
+                  assert(valp);
+
+                  /* try to remove any duplicate names, depending on the
+                   * implementation used in my_setenv() the iteration might
+                   * not be necessary, but let's be safe.
+                   */
+                  for (i = 0; i < count; ++i)
+                      my_setenv(name, 0);
+
+                  /* and set it back to the value we set $ENV{name} to */
+                  my_setenv(name, SvPV_nolen(*valp));
+              }
+          }
+          SvREFCNT_dec_NN(dups);
       }
 #endif /* USE_ENVIRON_ARRAY */
 #endif /* !PERL_MICRO */
