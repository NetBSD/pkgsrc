$NetBSD: patch-Makefile.PL,v 1.5 2020/03/21 15:36:33 taca Exp $

  - enable build of qmail-spamc
  - some files (local.cf, *.pre) are managed by pkgsrc, disable
    their installation.
  - pkgsrc creates B_DATADIR, so there is no need to re-set permissions

--- Makefile.PL.orig	2015-04-28 15:57:01.000000000 -0400
+++ Makefile.PL	2015-09-09 14:59:06.000000000 -0400
@@ -139,6 +139,7 @@
       'spamassassin.raw' => 'spamassassin',
       'sa-learn.raw'     => 'sa-learn',
       'sa-update.raw'    => 'sa-update',
+      'spamc/qmail-spamc.c' => 'spamc/qmail-spamc$(EXE_EXT)',
       'sa-compile.raw'   => 'sa-compile',
       'sa-awl.raw'       => 'sa-awl',
       'sa-check_spamd.raw' => 'sa-check_spamd',
@@ -1120,15 +1121,16 @@
 
 conf__install:
 	-$(MKPATH) $(B_CONFDIR)
-	$(PERL) -MFile::Copy -e "copy(q[rules/local.cf], q{$(B_CONFDIR)/local.cf}) unless -f q{$(B_CONFDIR)/local.cf}"
-	$(PERL) -MFile::Copy -e "copy(q[rules/init.pre], q{$(B_CONFDIR)/init.pre}) unless -f q{$(B_CONFDIR)/init.pre}"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v310.pre], q{$(B_CONFDIR)/v310.pre}) unless -f q{$(B_CONFDIR)/v310.pre}"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v312.pre], q{$(B_CONFDIR)/v312.pre}) unless -f q{$(B_CONFDIR)/v312.pre}"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v320.pre], q{$(B_CONFDIR)/v320.pre}) unless -f q{$(B_CONFDIR)/v320.pre}"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v330.pre], q{$(B_CONFDIR)/v330.pre}) unless -f q{$(B_CONFDIR)/v330.pre}"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v340.pre], q{$(B_CONFDIR)/v340.pre}) unless -f q{$(B_CONFDIR)/v340.pre}"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v341.pre], q{$(B_CONFDIR)/v341.pre}) unless -f q{$(B_CONFDIR)/v341.pre}"
-	$(PERL) -MFile::Copy -e "copy(q[rules/v342.pre], q{$(B_CONFDIR)/v342.pre}) unless -f q{$(B_CONFDIR)/v342.pre}"
+	# manage local.cf and *.pre through pkgsrc .mk files
+	# $(PERL) -MFile::Copy -e "copy(q[rules/local.cf], q{$(B_CONFDIR)/local.cf}) unless -f q{$(B_CONFDIR)/local.cf}"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/init.pre], q{$(B_CONFDIR)/init.pre}) unless -f q{$(B_CONFDIR)/init.pre}"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v310.pre], q{$(B_CONFDIR)/v310.pre}) unless -f q{$(B_CONFDIR)/v310.pre}"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v312.pre], q{$(B_CONFDIR)/v312.pre}) unless -f q{$(B_CONFDIR)/v312.pre}"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v320.pre], q{$(B_CONFDIR)/v320.pre}) unless -f q{$(B_CONFDIR)/v320.pre}"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v330.pre], q{$(B_CONFDIR)/v330.pre}) unless -f q{$(B_CONFDIR)/v330.pre}"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v340.pre], q{$(B_CONFDIR)/v340.pre}) unless -f q{$(B_CONFDIR)/v340.pre}"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v341.pre], q{$(B_CONFDIR)/v341.pre}) unless -f q{$(B_CONFDIR)/v341.pre}"
+	# $(PERL) -MFile::Copy -e "copy(q[rules/v342.pre], q{$(B_CONFDIR)/v342.pre}) unless -f q{$(B_CONFDIR)/v342.pre}"
   
 
 data__install:
  	-$(MKPATH) $(B_DATADIR)
 	$(PERL) -e "map unlink, <$(B_DATADIR)/*>"
 	$(PREPROCESS) $(FIXVARS) -m$(PERM_RW) -Irules -O$(B_DATADIR) $(DATAFILES)
-	$(CHMOD) $(PERM_RWX) $(B_DATADIR)
+	# no change of directory created by pkgsrc
+	# $(CHMOD) $(PERM_RWX) $(B_DATADIR)
 
 text_html_doc: made-doc-stamp
 	$(NOOP)
