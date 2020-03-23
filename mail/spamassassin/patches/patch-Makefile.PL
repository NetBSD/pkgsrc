$NetBSD: patch-Makefile.PL,v 1.6 2020/03/23 18:45:47 gdt Exp $

  - enable build of qmail-spamc
  - some files (local.cf, *.pre) are managed by pkgsrc, disable
    their installation.
  - pkgsrc creates B_DATADIR, so there is no need to re-set permissions

--- Makefile.PL.orig	2020-01-25 02:51:33.000000000 +0000
+++ Makefile.PL
@@ -139,6 +139,7 @@ my %makefile = (
       'spamassassin.raw' => 'spamassassin',
       'sa-learn.raw'     => 'sa-learn',
       'sa-update.raw'    => 'sa-update',
+      'spamc/qmail-spamc.c' => 'spamc/qmail-spamc$(EXE_EXT)',
       'sa-compile.raw'   => 'sa-compile',
       'sa-awl.raw'       => 'sa-awl',
       'sa-check_spamd.raw' => 'sa-check_spamd',
@@ -1120,22 +1121,24 @@ qmail/qmail-spamc$(EXE_EXT): spamc/qmail
 
 conf__install:
 	-$(MKPATH) $(B_CONFDIR)
-	$(PERL) -MFile::Copy -e "copy(q[rules/local.cf], q[$(B_CONFDIR)/local.cf]) unless -f q[$(B_CONFDIR)/local.cf]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/init.pre], q[$(B_CONFDIR)/init.pre]) unless -f q[$(B_CONFDIR)/init.pre]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v310.pre], q[$(B_CONFDIR)/v310.pre]) unless -f q[$(B_CONFDIR)/v310.pre]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v312.pre], q[$(B_CONFDIR)/v312.pre]) unless -f q[$(B_CONFDIR)/v312.pre]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v320.pre], q[$(B_CONFDIR)/v320.pre]) unless -f q[$(B_CONFDIR)/v320.pre]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v330.pre], q[$(B_CONFDIR)/v330.pre]) unless -f q[$(B_CONFDIR)/v330.pre]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v340.pre], q[$(B_CONFDIR)/v340.pre]) unless -f q[$(B_CONFDIR)/v340.pre]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v341.pre], q[$(B_CONFDIR)/v341.pre]) unless -f q[$(B_CONFDIR)/v341.pre]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v342.pre], q[$(B_CONFDIR)/v342.pre]) unless -f q[$(B_CONFDIR)/v342.pre]"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v343.pre], q[$(B_CONFDIR)/v343.pre]) unless -f q[$(B_CONFDIR)/v343.pre]"
+	# manage local.cf and *.pre through pkgsrc .mk files
+	# $(PERL) -MFile::Copy -e "copy(q[rules/local.cf], q[$(B_CONFDIR)/local.cf]) unless -f q[$(B_CONFDIR)/local.cf]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/init.pre], q[$(B_CONFDIR)/init.pre]) unless -f q[$(B_CONFDIR)/init.pre]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v310.pre], q[$(B_CONFDIR)/v310.pre]) unless -f q[$(B_CONFDIR)/v310.pre]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v312.pre], q[$(B_CONFDIR)/v312.pre]) unless -f q[$(B_CONFDIR)/v312.pre]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v320.pre], q[$(B_CONFDIR)/v320.pre]) unless -f q[$(B_CONFDIR)/v320.pre]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v330.pre], q[$(B_CONFDIR)/v330.pre]) unless -f q[$(B_CONFDIR)/v330.pre]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v340.pre], q[$(B_CONFDIR)/v340.pre]) unless -f q[$(B_CONFDIR)/v340.pre]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v341.pre], q[$(B_CONFDIR)/v341.pre]) unless -f q[$(B_CONFDIR)/v341.pre]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v342.pre], q[$(B_CONFDIR)/v342.pre]) unless -f q[$(B_CONFDIR)/v342.pre]"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v343.pre], q[$(B_CONFDIR)/v343.pre]) unless -f q[$(B_CONFDIR)/v343.pre]"
 
 data__install:
 	-$(MKPATH) $(B_DATADIR)
 	$(PERL) -e "map unlink, <$(B_DATADIR)/*>"
 	$(PREPROCESS) $(FIXVARS) -m$(PERM_RW) -Irules -O$(B_DATADIR) $(DATAFILES)
-	$(CHMOD) $(PERM_RWX) $(B_DATADIR)
+	# no change of directory created by pkgsrc
+	# $(CHMOD) $(PERM_RWX) $(B_DATADIR)
 
 text_html_doc: made-doc-stamp
 	$(NOOP)
