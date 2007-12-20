# DO NOT EDIT -- AUTOMATICALLY GENERATED

########################################
# Section 1: Global make variables
########################################

FS_BASE_DEPS = subversion/libsvn_fs_base/libsvn_fs_base-1.la
FS_BASE_LINK = ../../subversion/libsvn_fs_base/libsvn_fs_base-1.la

FS_FS_DEPS = subversion/libsvn_fs_fs/libsvn_fs_fs-1.la
FS_FS_LINK = ../../subversion/libsvn_fs_fs/libsvn_fs_fs-1.la

RA_DAV_DEPS = subversion/libsvn_ra_dav/libsvn_ra_dav-1.la
RA_DAV_LINK = ../../subversion/libsvn_ra_dav/libsvn_ra_dav-1.la

RA_LOCAL_DEPS = subversion/libsvn_ra_local/libsvn_ra_local-1.la
RA_LOCAL_LINK = ../../subversion/libsvn_ra_local/libsvn_ra_local-1.la

RA_SERF_DEPS = subversion/libsvn_ra_serf/libsvn_ra_serf-1.la
RA_SERF_LINK = ../../subversion/libsvn_ra_serf/libsvn_ra_serf-1.la

RA_SVN_DEPS = subversion/libsvn_ra_svn/libsvn_ra_svn-1.la
RA_SVN_LINK = ../../subversion/libsvn_ra_svn/libsvn_ra_svn-1.la

BUILD_DIRS = subversion/tests/libsvn_fs_base subversion/tests/libsvn_subr tools/diff subversion/tests/libsvn_diff subversion/tests/libsvn_fs subversion/bindings/java/javahl/src/org/tigris/subversion/javahl subversion/bindings/java/javahl/classes subversion/bindings/java/javahl/include subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests subversion/libsvn_client subversion/libsvn_delta subversion/libsvn_diff subversion/libsvn_fs subversion/libsvn_fs_base subversion/libsvn_fs_base/bdb subversion/libsvn_fs_base/util subversion/libsvn_fs_fs subversion/libsvn_ra subversion/libsvn_ra_dav subversion/libsvn_ra_local subversion/libsvn_ra_serf subversion/libsvn_ra_svn subversion/libsvn_repos subversion/libsvn_subr subversion/bindings/swig/perl/libsvn_swig_perl subversion/bindings/swig/python/libsvn_swig_py subversion/bindings/swig/ruby/libsvn_swig_ruby subversion/tests subversion/libsvn_wc subversion/bindings/java/javahl/native subversion/po subversion/mod_authz_svn subversion/mod_dav_svn contrib/client-side subversion/tests/libsvn_ra_local subversion/tests/libsvn_delta subversion/tests/libsvn_repos subversion/svn contrib/client-side/svn-push subversion/svnadmin tools/server-side subversion/svndumpfilter subversion/svnlook subversion/svnserve subversion/svnsync subversion/svnversion subversion/bindings/swig subversion/tests/libsvn_wc subversion/tests/cmdline subversion/bindings/swig/python subversion/bindings/swig/perl subversion/bindings/swig/ruby subversion/bindings/swig/proxy

BDB_TEST_DEPS = subversion/tests/libsvn_fs_base/changes-test$(EXEEXT) subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT) subversion/tests/libsvn_fs_base/key-test$(EXEEXT) subversion/tests/libsvn_fs_base/skel-test$(EXEEXT) subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT)

BDB_TEST_PROGRAMS = subversion/tests/libsvn_fs_base/changes-test$(EXEEXT) subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT) subversion/tests/libsvn_fs_base/key-test$(EXEEXT) subversion/tests/libsvn_fs_base/skel-test$(EXEEXT) subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT)

TEST_DEPS = subversion/tests/libsvn_subr/compat-test$(EXEEXT) subversion/tests/libsvn_subr/config-test$(EXEEXT) subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT) subversion/tests/libsvn_fs/fs-test$(EXEEXT) subversion/tests/libsvn_subr/hashdump-test$(EXEEXT) subversion/tests/libsvn_fs/locks-test$(EXEEXT) subversion/tests/libsvn_subr/opt-test$(EXEEXT) subversion/tests/libsvn_subr/path-test$(EXEEXT) subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT) subversion/tests/libsvn_delta/random-test$(EXEEXT) subversion/tests/libsvn_repos/repos-test$(EXEEXT) subversion/tests/libsvn_subr/stream-test$(EXEEXT) subversion/tests/libsvn_subr/string-test$(EXEEXT) subversion/tests/libsvn_delta/svndiff-test$(EXEEXT) subversion/tests/libsvn_subr/target-test$(EXEEXT) subversion/tests/libsvn_subr/time-test$(EXEEXT) subversion/tests/libsvn_wc/translate-test$(EXEEXT) subversion/tests/libsvn_subr/utf-test$(EXEEXT) subversion/tests/libsvn_delta/vdelta-test$(EXEEXT) subversion/tests/libsvn_subr/target-test.py subversion/tests/cmdline/getopt_tests.py subversion/tests/cmdline/basic_tests.py subversion/tests/cmdline/commit_tests.py subversion/tests/cmdline/update_tests.py subversion/tests/cmdline/switch_tests.py subversion/tests/cmdline/prop_tests.py subversion/tests/cmdline/schedule_tests.py subversion/tests/cmdline/log_tests.py subversion/tests/cmdline/copy_tests.py subversion/tests/cmdline/diff_tests.py subversion/tests/cmdline/export_tests.py subversion/tests/cmdline/externals_tests.py subversion/tests/cmdline/merge_tests.py subversion/tests/cmdline/revert_tests.py subversion/tests/cmdline/stat_tests.py subversion/tests/cmdline/trans_tests.py subversion/tests/cmdline/autoprop_tests.py subversion/tests/cmdline/blame_tests.py subversion/tests/cmdline/special_tests.py subversion/tests/cmdline/svnadmin_tests.py subversion/tests/cmdline/svnlook_tests.py subversion/tests/cmdline/svnversion_tests.py subversion/tests/cmdline/utf8_tests.py subversion/tests/cmdline/history_tests.py subversion/tests/cmdline/lock_tests.py subversion/tests/cmdline/cat_tests.py subversion/tests/cmdline/import_tests.py subversion/tests/cmdline/svnsync_tests.py subversion/tests/cmdline/authz_tests.py

TEST_PROGRAMS = subversion/tests/libsvn_subr/compat-test$(EXEEXT) subversion/tests/libsvn_subr/config-test$(EXEEXT) subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT) subversion/tests/libsvn_fs/fs-test$(EXEEXT) subversion/tests/libsvn_subr/hashdump-test$(EXEEXT) subversion/tests/libsvn_fs/locks-test$(EXEEXT) subversion/tests/libsvn_subr/opt-test$(EXEEXT) subversion/tests/libsvn_subr/path-test$(EXEEXT) subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT) subversion/tests/libsvn_delta/random-test$(EXEEXT) subversion/tests/libsvn_repos/repos-test$(EXEEXT) subversion/tests/libsvn_subr/stream-test$(EXEEXT) subversion/tests/libsvn_subr/string-test$(EXEEXT) subversion/tests/libsvn_subr/time-test$(EXEEXT) subversion/tests/libsvn_wc/translate-test$(EXEEXT) subversion/tests/libsvn_subr/utf-test$(EXEEXT) subversion/tests/libsvn_subr/target-test.py subversion/tests/cmdline/getopt_tests.py subversion/tests/cmdline/basic_tests.py subversion/tests/cmdline/commit_tests.py subversion/tests/cmdline/update_tests.py subversion/tests/cmdline/switch_tests.py subversion/tests/cmdline/prop_tests.py subversion/tests/cmdline/schedule_tests.py subversion/tests/cmdline/log_tests.py subversion/tests/cmdline/copy_tests.py subversion/tests/cmdline/diff_tests.py subversion/tests/cmdline/export_tests.py subversion/tests/cmdline/externals_tests.py subversion/tests/cmdline/merge_tests.py subversion/tests/cmdline/revert_tests.py subversion/tests/cmdline/stat_tests.py subversion/tests/cmdline/trans_tests.py subversion/tests/cmdline/autoprop_tests.py subversion/tests/cmdline/blame_tests.py subversion/tests/cmdline/special_tests.py subversion/tests/cmdline/svnadmin_tests.py subversion/tests/cmdline/svnlook_tests.py subversion/tests/cmdline/svnversion_tests.py subversion/tests/cmdline/utf8_tests.py subversion/tests/cmdline/history_tests.py subversion/tests/cmdline/lock_tests.py subversion/tests/cmdline/cat_tests.py subversion/tests/cmdline/import_tests.py subversion/tests/cmdline/svnsync_tests.py subversion/tests/cmdline/authz_tests.py

MANPAGES = subversion/svn/svn.1 subversion/svnadmin/svnadmin.1 subversion/svndumpfilter/svndumpfilter.1 subversion/svnlook/svnlook.1 subversion/svnserve/svnserve.8 subversion/svnserve/svnserve.conf.5 subversion/svnsync/svnsync.1 subversion/svnversion/svnversion.1

CLEAN_FILES = contrib/client-side/mucc$(EXEEXT) contrib/client-side/svn-push/svn-push$(EXEEXT) subversion/svn/svn$(EXEEXT) subversion/svnadmin/svnadmin$(EXEEXT) subversion/svndumpfilter/svndumpfilter$(EXEEXT) subversion/svnlook/svnlook$(EXEEXT) subversion/svnserve/svnserve$(EXEEXT) subversion/svnsync/svnsync$(EXEEXT) subversion/svnversion/svnversion$(EXEEXT) subversion/tests/libsvn_delta/random-test$(EXEEXT) subversion/tests/libsvn_delta/svndiff-test$(EXEEXT) subversion/tests/libsvn_delta/vdelta-test$(EXEEXT) subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT) subversion/tests/libsvn_fs/fs-test$(EXEEXT) subversion/tests/libsvn_fs/locks-test$(EXEEXT) subversion/tests/libsvn_fs_base/changes-test$(EXEEXT) subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT) subversion/tests/libsvn_fs_base/key-test$(EXEEXT) subversion/tests/libsvn_fs_base/skel-test$(EXEEXT) subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT) subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT) subversion/tests/libsvn_repos/repos-test$(EXEEXT) subversion/tests/libsvn_subr/compat-test$(EXEEXT) subversion/tests/libsvn_subr/config-test$(EXEEXT) subversion/tests/libsvn_subr/hashdump-test$(EXEEXT) subversion/tests/libsvn_subr/opt-test$(EXEEXT) subversion/tests/libsvn_subr/path-test$(EXEEXT) subversion/tests/libsvn_subr/stream-test$(EXEEXT) subversion/tests/libsvn_subr/string-test$(EXEEXT) subversion/tests/libsvn_subr/target-test$(EXEEXT) subversion/tests/libsvn_subr/time-test$(EXEEXT) subversion/tests/libsvn_subr/utf-test$(EXEEXT) subversion/tests/libsvn_wc/translate-test$(EXEEXT) tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT)

SWIG_INCLUDES = -I$(abs_srcdir)/subversion/include \
  -I$(abs_srcdir)/subversion/bindings/swig \
  -I$(abs_srcdir)/subversion/bindings/swig/include \
  -I$(abs_srcdir)/subversion/bindings/swig/proxy \
  -I$(abs_builddir)/subversion/bindings/swig/proxy \
  $(SVN_APR_INCLUDES) $(SVN_APRUTIL_INCLUDES)

RELEASE_MODE = 1


########################################
# Section 2: SWIG headers (wrappers and external runtimes)
########################################


########################################
# Section 3: SWIG autogen rules
########################################

autogen-swig-py: $(top_srcdir)/subversion/bindings/swig/python/core.c $(top_srcdir)/subversion/bindings/swig/python/svn_client.c $(top_srcdir)/subversion/bindings/swig/python/svn_delta.c $(top_srcdir)/subversion/bindings/swig/python/svn_fs.c $(top_srcdir)/subversion/bindings/swig/python/svn_ra.c $(top_srcdir)/subversion/bindings/swig/python/svn_repos.c $(top_srcdir)/subversion/bindings/swig/python/svn_wc.c
autogen-swig: autogen-swig-py

autogen-swig-pl: $(top_srcdir)/subversion/bindings/swig/perl/native/core.c $(top_srcdir)/subversion/bindings/swig/perl/native/svn_client.c $(top_srcdir)/subversion/bindings/swig/perl/native/svn_delta.c $(top_srcdir)/subversion/bindings/swig/perl/native/svn_fs.c $(top_srcdir)/subversion/bindings/swig/perl/native/svn_ra.c $(top_srcdir)/subversion/bindings/swig/perl/native/svn_repos.c $(top_srcdir)/subversion/bindings/swig/perl/native/svn_wc.c
autogen-swig: autogen-swig-pl

autogen-swig-rb: $(top_srcdir)/subversion/bindings/swig/ruby/core.c $(top_srcdir)/subversion/bindings/swig/ruby/svn_client.c $(top_srcdir)/subversion/bindings/swig/ruby/svn_delta.c $(top_srcdir)/subversion/bindings/swig/ruby/svn_fs.c $(top_srcdir)/subversion/bindings/swig/ruby/svn_ra.c $(top_srcdir)/subversion/bindings/swig/ruby/svn_repos.c $(top_srcdir)/subversion/bindings/swig/ruby/svn_wc.c
autogen-swig: autogen-swig-rb



########################################
# Section 4: Rules to build SWIG .c files from .i files
########################################



########################################
# Section 5: Individual target build rules
########################################

changes_test_PATH = subversion/tests/libsvn_fs_base
changes_test_DEPS =  subversion/tests/libsvn_fs_base/changes-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la
changes_test_OBJECTS = changes-test.o
subversion/tests/libsvn_fs_base/changes-test$(EXEEXT): $(changes_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o changes-test$(EXEEXT)  $(changes_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

compat_test_PATH = subversion/tests/libsvn_subr
compat_test_DEPS =  subversion/tests/libsvn_subr/compat-test.o subversion/tests/libsvn_test-1.la
compat_test_OBJECTS = compat-test.o
subversion/tests/libsvn_subr/compat-test$(EXEEXT): $(compat_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o compat-test$(EXEEXT)  $(compat_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

config_test_PATH = subversion/tests/libsvn_subr
config_test_DEPS =  subversion/tests/libsvn_subr/config-test.o subversion/tests/libsvn_test-1.la
config_test_OBJECTS = config-test.o
subversion/tests/libsvn_subr/config-test$(EXEEXT): $(config_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o config-test$(EXEEXT)  $(config_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

diff_PATH = tools/diff
diff_DEPS =  tools/diff/diff.o
diff_OBJECTS = diff.o
tools/diff/diff$(EXEEXT): $(diff_DEPS)
	cd tools/diff && $(LINK) -o diff$(EXEEXT)  $(diff_OBJECTS) -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

diff_diff3_test_PATH = subversion/tests/libsvn_diff
diff_diff3_test_DEPS =  subversion/tests/libsvn_diff/diff-diff3-test.o subversion/tests/libsvn_test-1.la
diff_diff3_test_OBJECTS = diff-diff3-test.o
subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT): $(diff_diff3_test_DEPS)
	cd subversion/tests/libsvn_diff && $(LINK) -o diff-diff3-test$(EXEEXT)  $(diff_diff3_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

diff3_PATH = tools/diff
diff3_DEPS =  tools/diff/diff3.o
diff3_OBJECTS = diff3.o
tools/diff/diff3$(EXEEXT): $(diff3_DEPS)
	cd tools/diff && $(LINK) -o diff3$(EXEEXT)  $(diff3_OBJECTS) -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

diff4_PATH = tools/diff
diff4_DEPS =  tools/diff/diff4.o
diff4_OBJECTS = diff4.o
tools/diff/diff4$(EXEEXT): $(diff4_DEPS)
	cd tools/diff && $(LINK) -o diff4$(EXEEXT)  $(diff4_OBJECTS) -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

fs_base_test_PATH = subversion/tests/libsvn_fs_base
fs_base_test_DEPS =  subversion/tests/libsvn_fs_base/fs-base-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la
fs_base_test_OBJECTS = fs-base-test.o
subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT): $(fs_base_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o fs-base-test$(EXEEXT)  $(fs_base_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

fs_test_PATH = subversion/tests/libsvn_fs
fs_test_DEPS =  subversion/tests/libsvn_fs/fs-test.o subversion/tests/libsvn_test-1.la
fs_test_OBJECTS = fs-test.o
subversion/tests/libsvn_fs/fs-test$(EXEEXT): $(fs_test_DEPS)
	cd subversion/tests/libsvn_fs && $(LINK) -o fs-test$(EXEEXT)  $(fs_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

hashdump_test_PATH = subversion/tests/libsvn_subr
hashdump_test_DEPS =  subversion/tests/libsvn_subr/hashdump-test.o subversion/tests/libsvn_test-1.la
hashdump_test_OBJECTS = hashdump-test.o
subversion/tests/libsvn_subr/hashdump-test$(EXEEXT): $(hashdump_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o hashdump-test$(EXEEXT)  $(hashdump_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

javahl_java_PATH = subversion/bindings/java/javahl/classes
javahl_java_HEADERS = 
javahl_java_OBJECTS = subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PropertyData.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNInputStream.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyAction.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Info.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/DirEntry.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyStatus.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NodeKind.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Info2.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/LogMessage.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/BlameCallback.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Path.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword2.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/OutputInterface.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Notify2.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNAdmin.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/StatusKind.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyInformation.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Revision.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Lock.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Version.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/JNIError.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitItemStateFlags.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ClientException.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNOutputStream.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/LockStatus.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ScheduleKind.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ChangePath.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Status.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientInterface.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClient.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NativeResources.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/InputInterface.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword3.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/RevisionKind.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientSynchronized.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientLogLevel.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Notify.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitMessage.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitItem.class
javahl_java_DEPS = $(javahl_java_HEADERS) $(javahl_java_OBJECTS)  
javahl-java: $(javahl_java_DEPS)
javahl_java_SRC = $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/PropertyData.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNInputStream.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NotifyAction.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Info.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/DirEntry.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NotifyStatus.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NodeKind.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Info2.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/LogMessage.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/BlameCallback.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Path.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/PromptUserPassword2.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/OutputInterface.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Notify2.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/PromptUserPassword.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNAdmin.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/StatusKind.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NotifyInformation.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Revision.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Lock.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Version.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/JNIError.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/CommitItemStateFlags.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/ClientException.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNOutputStream.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/LockStatus.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/ScheduleKind.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/ChangePath.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Status.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNClientInterface.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNClient.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NativeResources.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/InputInterface.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/PromptUserPassword3.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/RevisionKind.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNClientSynchronized.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNClientLogLevel.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Notify.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/CommitMessage.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/CommitItem.java
$(javahl_java_OBJECTS): $(javahl_java_SRC)
	$(COMPILE_JAVAHL_JAVAC) -d subversion/bindings/java/javahl/classes -classpath subversion/bindings/java/javahl/classes:$(javahl_java_CLASSPATH) $(javahl_java_SRC)


javahl_javah_PATH = subversion/bindings/java/javahl/include
javahl_javah_HEADERS = subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_PropertyData.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNInputStream.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NotifyAction.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Info.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_DirEntry.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NotifyStatus.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NodeKind.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Info2.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_LogMessage.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_BlameCallback.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Path.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_PromptUserPassword2.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_OutputInterface.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Notify2.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_PromptUserPassword.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNAdmin.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_StatusKind.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NotifyInformation.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Revision.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Lock.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Version.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_JNIError.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_CommitItemStateFlags.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_ClientException.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNOutputStream.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_LockStatus.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_ScheduleKind.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_ChangePath.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Status.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNClientInterface.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNClient.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NativeResources.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_InputInterface.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_PromptUserPassword3.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_RevisionKind.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNClientSynchronized.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNClientLogLevel.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Notify.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_CommitMessage.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_CommitItem.h
javahl_javah_OBJECTS = 
javahl_javah_DEPS = $(javahl_javah_HEADERS) $(javahl_javah_OBJECTS) $(javahl_java_DEPS) 
javahl-javah: $(javahl_javah_DEPS)
javahl_javah_CLASS_FILENAMES = subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PropertyData.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNInputStream.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyAction.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Info.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/DirEntry.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyStatus.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NodeKind.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Info2.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/LogMessage.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/BlameCallback.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Path.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword2.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/OutputInterface.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Notify2.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNAdmin.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/StatusKind.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyInformation.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Revision.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Lock.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Version.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/JNIError.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitItemStateFlags.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ClientException.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNOutputStream.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/LockStatus.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ScheduleKind.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ChangePath.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Status.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientInterface.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClient.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NativeResources.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/InputInterface.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword3.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/RevisionKind.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientSynchronized.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientLogLevel.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Notify.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitMessage.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitItem.class
javahl_javah_CLASSES = org.tigris.subversion.javahl.PropertyData org.tigris.subversion.javahl.SVNInputStream org.tigris.subversion.javahl.NotifyAction org.tigris.subversion.javahl.Info org.tigris.subversion.javahl.DirEntry org.tigris.subversion.javahl.NotifyStatus org.tigris.subversion.javahl.NodeKind org.tigris.subversion.javahl.Info2 org.tigris.subversion.javahl.LogMessage org.tigris.subversion.javahl.BlameCallback org.tigris.subversion.javahl.Path org.tigris.subversion.javahl.PromptUserPassword2 org.tigris.subversion.javahl.OutputInterface org.tigris.subversion.javahl.Notify2 org.tigris.subversion.javahl.PromptUserPassword org.tigris.subversion.javahl.SVNAdmin org.tigris.subversion.javahl.StatusKind org.tigris.subversion.javahl.NotifyInformation org.tigris.subversion.javahl.Revision org.tigris.subversion.javahl.Lock org.tigris.subversion.javahl.Version org.tigris.subversion.javahl.JNIError org.tigris.subversion.javahl.CommitItemStateFlags org.tigris.subversion.javahl.ClientException org.tigris.subversion.javahl.SVNOutputStream org.tigris.subversion.javahl.LockStatus org.tigris.subversion.javahl.ScheduleKind org.tigris.subversion.javahl.ChangePath org.tigris.subversion.javahl.Status org.tigris.subversion.javahl.SVNClientInterface org.tigris.subversion.javahl.SVNClient org.tigris.subversion.javahl.NativeResources org.tigris.subversion.javahl.InputInterface org.tigris.subversion.javahl.PromptUserPassword3 org.tigris.subversion.javahl.RevisionKind org.tigris.subversion.javahl.SVNClientSynchronized org.tigris.subversion.javahl.SVNClientLogLevel org.tigris.subversion.javahl.Notify org.tigris.subversion.javahl.CommitMessage org.tigris.subversion.javahl.CommitItem
$(javahl_javah_HEADERS): $(javahl_javah_CLASS_FILENAMES)
	$(COMPILE_JAVAHL_JAVAH) -force -d subversion/bindings/java/javahl/include -classpath subversion/bindings/java/javahl/classes:$(javahl_javah_CLASSPATH) $(javahl_javah_CLASSES)


javahl_tests_PATH = subversion/bindings/java/javahl/classes
javahl_tests_HEADERS = 
javahl_tests_OBJECTS = subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/tests/SVNTests.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/tests/WC.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/tests/SVNAdminTests.class subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/tests/BasicTests.class
javahl_tests_DEPS = $(javahl_tests_HEADERS) $(javahl_tests_OBJECTS)  
javahl-tests: $(javahl_tests_DEPS)
javahl_tests_SRC = $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests/SVNTests.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests/WC.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests/SVNAdminTests.java $(abs_srcdir)/subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests/BasicTests.java
$(javahl_tests_OBJECTS): $(javahl_tests_SRC)
	$(COMPILE_JAVAHL_JAVAC) -d subversion/bindings/java/javahl/classes -classpath subversion/bindings/java/javahl/classes:$(javahl_tests_CLASSPATH) $(javahl_tests_SRC)


key_test_PATH = subversion/tests/libsvn_fs_base
key_test_DEPS =  subversion/tests/libsvn_fs_base/key-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la
key_test_OBJECTS = key-test.o
subversion/tests/libsvn_fs_base/key-test$(EXEEXT): $(key_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o key-test$(EXEEXT)  $(key_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_client_PATH = subversion/libsvn_client
libsvn_client_DEPS =  subversion/libsvn_client/add.lo subversion/libsvn_client/blame.lo subversion/libsvn_client/cat.lo subversion/libsvn_client/checkout.lo subversion/libsvn_client/cleanup.lo subversion/libsvn_client/commit.lo subversion/libsvn_client/commit_util.lo subversion/libsvn_client/compat_providers.lo subversion/libsvn_client/copy.lo subversion/libsvn_client/ctx.lo subversion/libsvn_client/delete.lo subversion/libsvn_client/diff.lo subversion/libsvn_client/export.lo subversion/libsvn_client/externals.lo subversion/libsvn_client/info.lo subversion/libsvn_client/list.lo subversion/libsvn_client/locking_commands.lo subversion/libsvn_client/log.lo subversion/libsvn_client/prop_commands.lo subversion/libsvn_client/ra.lo subversion/libsvn_client/relocate.lo subversion/libsvn_client/repos_diff.lo subversion/libsvn_client/repos_diff_summarize.lo subversion/libsvn_client/resolved.lo subversion/libsvn_client/revert.lo subversion/libsvn_client/revisions.lo subversion/libsvn_client/status.lo subversion/libsvn_client/switch.lo subversion/libsvn_client/update.lo subversion/libsvn_client/url.lo subversion/libsvn_client/util.lo subversion/libsvn_client/version.lo
libsvn_client_OBJECTS = add.lo blame.lo cat.lo checkout.lo cleanup.lo commit.lo commit_util.lo compat_providers.lo copy.lo ctx.lo delete.lo diff.lo export.lo externals.lo info.lo list.lo locking_commands.lo log.lo prop_commands.lo ra.lo relocate.lo repos_diff.lo repos_diff_summarize.lo resolved.lo revert.lo revisions.lo status.lo switch.lo update.lo url.lo util.lo version.lo
subversion/libsvn_client/libsvn_client-1.la: $(libsvn_client_DEPS)
	cd subversion/libsvn_client && $(LINK) -o libsvn_client-1.la $(LT_NO_UNDEFINED) $(libsvn_client_OBJECTS) -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_delta_PATH = subversion/libsvn_delta
libsvn_delta_DEPS =  subversion/libsvn_delta/cancel.lo subversion/libsvn_delta/compose_delta.lo subversion/libsvn_delta/debug_editor.lo subversion/libsvn_delta/default_editor.lo subversion/libsvn_delta/path_driver.lo subversion/libsvn_delta/svndiff.lo subversion/libsvn_delta/text_delta.lo subversion/libsvn_delta/vdelta.lo subversion/libsvn_delta/version.lo subversion/libsvn_delta/xdelta.lo
libsvn_delta_OBJECTS = cancel.lo compose_delta.lo debug_editor.lo default_editor.lo path_driver.lo svndiff.lo text_delta.lo vdelta.lo version.lo xdelta.lo
subversion/libsvn_delta/libsvn_delta-1.la: $(libsvn_delta_DEPS)
	cd subversion/libsvn_delta && $(LINK) -o libsvn_delta-1.la $(LT_NO_UNDEFINED) $(libsvn_delta_OBJECTS) -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_diff_PATH = subversion/libsvn_diff
libsvn_diff_DEPS =  subversion/libsvn_diff/diff.lo subversion/libsvn_diff/diff3.lo subversion/libsvn_diff/diff4.lo subversion/libsvn_diff/diff_file.lo subversion/libsvn_diff/lcs.lo subversion/libsvn_diff/token.lo subversion/libsvn_diff/util.lo
libsvn_diff_OBJECTS = diff.lo diff3.lo diff4.lo diff_file.lo lcs.lo token.lo util.lo
subversion/libsvn_diff/libsvn_diff-1.la: $(libsvn_diff_DEPS)
	cd subversion/libsvn_diff && $(LINK) -o libsvn_diff-1.la $(LT_NO_UNDEFINED) $(libsvn_diff_OBJECTS) -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_fs_PATH = subversion/libsvn_fs
install-ramod-lib: $(SVN_FS_LIB_INSTALL_DEPS)
libsvn_fs_DEPS = $(SVN_FS_LIB_DEPS) subversion/libsvn_fs/access.lo subversion/libsvn_fs/fs-loader.lo
libsvn_fs_OBJECTS = access.lo fs-loader.lo
subversion/libsvn_fs/libsvn_fs-1.la: $(libsvn_fs_DEPS)
	cd subversion/libsvn_fs && $(LINK) -o libsvn_fs-1.la $(LT_NO_UNDEFINED) $(libsvn_fs_OBJECTS) -lsvn_subr-1 $(SVN_FS_LIB_LINK) $(SVN_APR_LIBS) $(LIBS)

libsvn_fs_base_PATH = subversion/libsvn_fs_base
libsvn_fs_base_DEPS =  subversion/libsvn_fs_base/bdb/bdb-err.lo subversion/libsvn_fs_base/bdb/bdb_compat.lo subversion/libsvn_fs_base/bdb/changes-table.lo subversion/libsvn_fs_base/bdb/copies-table.lo subversion/libsvn_fs_base/bdb/dbt.lo subversion/libsvn_fs_base/bdb/env.lo subversion/libsvn_fs_base/bdb/lock-tokens-table.lo subversion/libsvn_fs_base/bdb/locks-table.lo subversion/libsvn_fs_base/bdb/nodes-table.lo subversion/libsvn_fs_base/bdb/reps-table.lo subversion/libsvn_fs_base/bdb/rev-table.lo subversion/libsvn_fs_base/bdb/strings-table.lo subversion/libsvn_fs_base/bdb/txn-table.lo subversion/libsvn_fs_base/bdb/uuids-table.lo subversion/libsvn_fs_base/dag.lo subversion/libsvn_fs_base/err.lo subversion/libsvn_fs_base/fs.lo subversion/libsvn_fs_base/id.lo subversion/libsvn_fs_base/key-gen.lo subversion/libsvn_fs_base/lock.lo subversion/libsvn_fs_base/node-rev.lo subversion/libsvn_fs_base/reps-strings.lo subversion/libsvn_fs_base/revs-txns.lo subversion/libsvn_fs_base/trail.lo subversion/libsvn_fs_base/tree.lo subversion/libsvn_fs_base/util/fs_skels.lo subversion/libsvn_fs_base/util/skel.lo subversion/libsvn_fs_base/uuid.lo
libsvn_fs_base_OBJECTS = bdb/bdb-err.lo bdb/bdb_compat.lo bdb/changes-table.lo bdb/copies-table.lo bdb/dbt.lo bdb/env.lo bdb/lock-tokens-table.lo bdb/locks-table.lo bdb/nodes-table.lo bdb/reps-table.lo bdb/rev-table.lo bdb/strings-table.lo bdb/txn-table.lo bdb/uuids-table.lo dag.lo err.lo fs.lo id.lo key-gen.lo lock.lo node-rev.lo reps-strings.lo revs-txns.lo trail.lo tree.lo util/fs_skels.lo util/skel.lo uuid.lo
subversion/libsvn_fs_base/libsvn_fs_base-1.la: $(libsvn_fs_base_DEPS)
	cd subversion/libsvn_fs_base && $(LINK) -o libsvn_fs_base-1.la $(LT_NO_UNDEFINED) $(libsvn_fs_base_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_DB_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_fs_fs_PATH = subversion/libsvn_fs_fs
libsvn_fs_fs_DEPS =  subversion/libsvn_fs_fs/dag.lo subversion/libsvn_fs_fs/err.lo subversion/libsvn_fs_fs/fs.lo subversion/libsvn_fs_fs/fs_fs.lo subversion/libsvn_fs_fs/id.lo subversion/libsvn_fs_fs/key-gen.lo subversion/libsvn_fs_fs/lock.lo subversion/libsvn_fs_fs/tree.lo
libsvn_fs_fs_OBJECTS = dag.lo err.lo fs.lo fs_fs.lo id.lo key-gen.lo lock.lo tree.lo
subversion/libsvn_fs_fs/libsvn_fs_fs-1.la: $(libsvn_fs_fs_DEPS)
	cd subversion/libsvn_fs_fs && $(LINK) -o libsvn_fs_fs-1.la $(LT_NO_UNDEFINED) $(libsvn_fs_fs_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_ra_PATH = subversion/libsvn_ra
install-lib: $(SVN_RA_LIB_INSTALL_DEPS)
libsvn_ra_DEPS = $(SVN_RA_LIB_DEPS) subversion/libsvn_ra/ra_loader.lo
libsvn_ra_OBJECTS = ra_loader.lo
subversion/libsvn_ra/libsvn_ra-1.la: $(libsvn_ra_DEPS)
	cd subversion/libsvn_ra && $(LINK) -o libsvn_ra-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_OBJECTS) -lsvn_subr-1 $(SVN_RA_LIB_LINK) $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_ra_dav_PATH = subversion/libsvn_ra_dav
libsvn_ra_dav_DEPS =  subversion/libsvn_ra_dav/commit.lo subversion/libsvn_ra_dav/fetch.lo subversion/libsvn_ra_dav/file_revs.lo subversion/libsvn_ra_dav/log.lo subversion/libsvn_ra_dav/merge.lo subversion/libsvn_ra_dav/options.lo subversion/libsvn_ra_dav/props.lo subversion/libsvn_ra_dav/replay.lo subversion/libsvn_ra_dav/session.lo subversion/libsvn_ra_dav/util.lo
libsvn_ra_dav_OBJECTS = commit.lo fetch.lo file_revs.lo log.lo merge.lo options.lo props.lo replay.lo session.lo util.lo
subversion/libsvn_ra_dav/libsvn_ra_dav-1.la: $(libsvn_ra_dav_DEPS)
	cd subversion/libsvn_ra_dav && $(LINK) -o libsvn_ra_dav-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_dav_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

libsvn_ra_local_PATH = subversion/libsvn_ra_local
libsvn_ra_local_DEPS =  subversion/libsvn_ra_local/ra_plugin.lo subversion/libsvn_ra_local/split_url.lo
libsvn_ra_local_OBJECTS = ra_plugin.lo split_url.lo
subversion/libsvn_ra_local/libsvn_ra_local-1.la: $(libsvn_ra_local_DEPS)
	cd subversion/libsvn_ra_local && $(LINK) -o libsvn_ra_local-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_local_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_ra_serf_PATH = subversion/libsvn_ra_serf
libsvn_ra_serf_DEPS =  subversion/libsvn_ra_serf/blame.lo subversion/libsvn_ra_serf/commit.lo subversion/libsvn_ra_serf/getdate.lo subversion/libsvn_ra_serf/getlocations.lo subversion/libsvn_ra_serf/getlocks.lo subversion/libsvn_ra_serf/locks.lo subversion/libsvn_ra_serf/log.lo subversion/libsvn_ra_serf/merge.lo subversion/libsvn_ra_serf/options.lo subversion/libsvn_ra_serf/property.lo subversion/libsvn_ra_serf/propfind_buckets.lo subversion/libsvn_ra_serf/replay.lo subversion/libsvn_ra_serf/serf.lo subversion/libsvn_ra_serf/update.lo subversion/libsvn_ra_serf/util.lo subversion/libsvn_ra_serf/xml.lo
libsvn_ra_serf_OBJECTS = blame.lo commit.lo getdate.lo getlocations.lo getlocks.lo locks.lo log.lo merge.lo options.lo property.lo propfind_buckets.lo replay.lo serf.lo update.lo util.lo xml.lo
subversion/libsvn_ra_serf/libsvn_ra_serf-1.la: $(libsvn_ra_serf_DEPS)
	cd subversion/libsvn_ra_serf && $(LINK) -o libsvn_ra_serf-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_serf_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(SVN_SERF_LIBS) $(LIBS)

libsvn_ra_svn_PATH = subversion/libsvn_ra_svn
libsvn_ra_svn_DEPS =  subversion/libsvn_ra_svn/client.lo subversion/libsvn_ra_svn/cram.lo subversion/libsvn_ra_svn/editor.lo subversion/libsvn_ra_svn/editorp.lo subversion/libsvn_ra_svn/marshal.lo subversion/libsvn_ra_svn/version.lo
libsvn_ra_svn_OBJECTS = client.lo cram.lo editor.lo editorp.lo marshal.lo version.lo
subversion/libsvn_ra_svn/libsvn_ra_svn-1.la: $(libsvn_ra_svn_DEPS)
	cd subversion/libsvn_ra_svn && $(LINK) -o libsvn_ra_svn-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_svn_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_repos_PATH = subversion/libsvn_repos
libsvn_repos_DEPS =  subversion/libsvn_repos/authz.lo subversion/libsvn_repos/commit.lo subversion/libsvn_repos/delta.lo subversion/libsvn_repos/dump.lo subversion/libsvn_repos/fs-wrap.lo subversion/libsvn_repos/hooks.lo subversion/libsvn_repos/load.lo subversion/libsvn_repos/log.lo subversion/libsvn_repos/node_tree.lo subversion/libsvn_repos/replay.lo subversion/libsvn_repos/reporter.lo subversion/libsvn_repos/repos.lo subversion/libsvn_repos/rev_hunt.lo
libsvn_repos_OBJECTS = authz.lo commit.lo delta.lo dump.lo fs-wrap.lo hooks.lo load.lo log.lo node_tree.lo replay.lo reporter.lo repos.lo rev_hunt.lo
subversion/libsvn_repos/libsvn_repos-1.la: $(libsvn_repos_DEPS)
	cd subversion/libsvn_repos && $(LINK) -o libsvn_repos-1.la $(LT_NO_UNDEFINED) $(libsvn_repos_OBJECTS) -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_subr_PATH = subversion/libsvn_subr
libsvn_subr_DEPS =  subversion/libsvn_subr/auth.lo subversion/libsvn_subr/cmdline.lo subversion/libsvn_subr/compat.lo subversion/libsvn_subr/config.lo subversion/libsvn_subr/config_auth.lo subversion/libsvn_subr/config_file.lo subversion/libsvn_subr/config_win.lo subversion/libsvn_subr/constructors.lo subversion/libsvn_subr/ctype.lo subversion/libsvn_subr/date.lo subversion/libsvn_subr/dso.lo subversion/libsvn_subr/error.lo subversion/libsvn_subr/hash.lo subversion/libsvn_subr/io.lo subversion/libsvn_subr/kitchensink.lo subversion/libsvn_subr/lock.lo subversion/libsvn_subr/md5.lo subversion/libsvn_subr/nls.lo subversion/libsvn_subr/opt.lo subversion/libsvn_subr/path.lo subversion/libsvn_subr/pool.lo subversion/libsvn_subr/prompt.lo subversion/libsvn_subr/quoprint.lo subversion/libsvn_subr/simple_providers.lo subversion/libsvn_subr/sorts.lo subversion/libsvn_subr/ssl_client_cert_providers.lo subversion/libsvn_subr/ssl_client_cert_pw_providers.lo subversion/libsvn_subr/ssl_server_trust_providers.lo subversion/libsvn_subr/stream.lo subversion/libsvn_subr/subst.lo subversion/libsvn_subr/svn_base64.lo subversion/libsvn_subr/svn_string.lo subversion/libsvn_subr/target.lo subversion/libsvn_subr/time.lo subversion/libsvn_subr/user.lo subversion/libsvn_subr/username_providers.lo subversion/libsvn_subr/utf.lo subversion/libsvn_subr/utf_validate.lo subversion/libsvn_subr/validate.lo subversion/libsvn_subr/version.lo subversion/libsvn_subr/xml.lo
libsvn_subr_OBJECTS = auth.lo cmdline.lo compat.lo config.lo config_auth.lo config_file.lo config_win.lo constructors.lo ctype.lo date.lo dso.lo error.lo hash.lo io.lo kitchensink.lo lock.lo md5.lo nls.lo opt.lo path.lo pool.lo prompt.lo quoprint.lo simple_providers.lo sorts.lo ssl_client_cert_providers.lo ssl_client_cert_pw_providers.lo ssl_server_trust_providers.lo stream.lo subst.lo svn_base64.lo svn_string.lo target.lo time.lo user.lo username_providers.lo utf.lo utf_validate.lo validate.lo version.lo xml.lo
subversion/libsvn_subr/libsvn_subr-1.la: $(libsvn_subr_DEPS)
	cd subversion/libsvn_subr && $(LINK) -o libsvn_subr-1.la $(LT_NO_UNDEFINED) $(libsvn_subr_OBJECTS) $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_swig_perl_PATH = subversion/bindings/swig/perl/libsvn_swig_perl
libsvn_swig_perl_DEPS =  subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.lo
libsvn_swig_perl_OBJECTS = swigutil_pl.lo
subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la: $(libsvn_swig_perl_DEPS)
	cd subversion/bindings/swig/perl/libsvn_swig_perl && $(LINK) -o libsvn_swig_perl-1.la $(LT_NO_UNDEFINED) $(libsvn_swig_perl_OBJECTS) -lsvn_subr-1 -lsvn_delta-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_swig_py_PATH = subversion/bindings/swig/python/libsvn_swig_py
libsvn_swig_py_DEPS =  subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.lo
libsvn_swig_py_OBJECTS = swigutil_py.lo
subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la: $(libsvn_swig_py_DEPS)
	cd subversion/bindings/swig/python/libsvn_swig_py && $(LINK) $(SWIG_PY_LIBS) -o libsvn_swig_py-1.la $(LT_NO_UNDEFINED) $(libsvn_swig_py_OBJECTS) -lsvn_client-1 -lsvn_subr-1 -lsvn_delta-1 -lsvn_wc-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_swig_ruby_PATH = subversion/bindings/swig/ruby/libsvn_swig_ruby
libsvn_swig_ruby_DEPS =  subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.lo
libsvn_swig_ruby_OBJECTS = swigutil_rb.lo
subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la: $(libsvn_swig_ruby_DEPS)
	cd subversion/bindings/swig/ruby/libsvn_swig_ruby && $(LINK) -o libsvn_swig_ruby-1.la $(LT_NO_UNDEFINED) $(libsvn_swig_ruby_OBJECTS) -lsvn_client-1 -lsvn_wc-1 -lsvn_subr-1 -lsvn_delta-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_test_PATH = subversion/tests
libsvn_test_DEPS =  subversion/tests/svn_test_editor.lo subversion/tests/svn_test_fs.lo subversion/tests/svn_test_main.lo
libsvn_test_OBJECTS = svn_test_editor.lo svn_test_fs.lo svn_test_main.lo
subversion/tests/libsvn_test-1.la: $(libsvn_test_DEPS)
	cd subversion/tests && $(LINK) -o libsvn_test-1.la  $(libsvn_test_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_wc_PATH = subversion/libsvn_wc
libsvn_wc_DEPS =  subversion/libsvn_wc/adm_crawler.lo subversion/libsvn_wc/adm_files.lo subversion/libsvn_wc/adm_ops.lo subversion/libsvn_wc/copy.lo subversion/libsvn_wc/diff.lo subversion/libsvn_wc/entries.lo subversion/libsvn_wc/lock.lo subversion/libsvn_wc/log.lo subversion/libsvn_wc/merge.lo subversion/libsvn_wc/props.lo subversion/libsvn_wc/questions.lo subversion/libsvn_wc/relocate.lo subversion/libsvn_wc/revision_status.lo subversion/libsvn_wc/status.lo subversion/libsvn_wc/translate.lo subversion/libsvn_wc/update_editor.lo subversion/libsvn_wc/util.lo
libsvn_wc_OBJECTS = adm_crawler.lo adm_files.lo adm_ops.lo copy.lo diff.lo entries.lo lock.lo log.lo merge.lo props.lo questions.lo relocate.lo revision_status.lo status.lo translate.lo update_editor.lo util.lo
subversion/libsvn_wc/libsvn_wc-1.la: $(libsvn_wc_DEPS)
	cd subversion/libsvn_wc && $(LINK) -o libsvn_wc-1.la $(LT_NO_UNDEFINED) $(libsvn_wc_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 -lsvn_diff-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvnjavahl_PATH = subversion/bindings/java/javahl/native
libsvnjavahl_DEPS = $(javahl_javah_DEPS) $(javahl_java_DEPS) subversion/bindings/java/javahl/native/BlameCallback.lo subversion/bindings/java/javahl/native/CommitMessage.lo subversion/bindings/java/javahl/native/EnumMapper.lo subversion/bindings/java/javahl/native/Inputer.lo subversion/bindings/java/javahl/native/JNIByteArray.lo subversion/bindings/java/javahl/native/JNICriticalSection.lo subversion/bindings/java/javahl/native/JNIMutex.lo subversion/bindings/java/javahl/native/JNIStackElement.lo subversion/bindings/java/javahl/native/JNIStringHolder.lo subversion/bindings/java/javahl/native/JNIThreadData.lo subversion/bindings/java/javahl/native/JNIUtil.lo subversion/bindings/java/javahl/native/MessageReceiver.lo subversion/bindings/java/javahl/native/Notify.lo subversion/bindings/java/javahl/native/Notify2.lo subversion/bindings/java/javahl/native/Outputer.lo subversion/bindings/java/javahl/native/Path.lo subversion/bindings/java/javahl/native/Pool.lo subversion/bindings/java/javahl/native/Prompter.lo subversion/bindings/java/javahl/native/Revision.lo subversion/bindings/java/javahl/native/SVNAdmin.lo subversion/bindings/java/javahl/native/SVNBase.lo subversion/bindings/java/javahl/native/SVNClient.lo subversion/bindings/java/javahl/native/Targets.lo subversion/bindings/java/javahl/native/libsvnjavahl.la.lo subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_Path.lo subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_SVNAdmin.lo subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_SVNClient.lo subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_Version.lo
libsvnjavahl_OBJECTS = BlameCallback.lo CommitMessage.lo EnumMapper.lo Inputer.lo JNIByteArray.lo JNICriticalSection.lo JNIMutex.lo JNIStackElement.lo JNIStringHolder.lo JNIThreadData.lo JNIUtil.lo MessageReceiver.lo Notify.lo Notify2.lo Outputer.lo Path.lo Pool.lo Prompter.lo Revision.lo SVNAdmin.lo SVNBase.lo SVNClient.lo Targets.lo libsvnjavahl.la.lo org_tigris_subversion_javahl_Path.lo org_tigris_subversion_javahl_SVNAdmin.lo org_tigris_subversion_javahl_SVNClient.lo org_tigris_subversion_javahl_Version.lo
subversion/bindings/java/javahl/native/libsvnjavahl-1.la: $(libsvnjavahl_DEPS)
	cd subversion/bindings/java/javahl/native && $(LINK_JAVAHL_CXX) -o libsvnjavahl-1.la $(LT_NO_UNDEFINED) $(libsvnjavahl_OBJECTS) -lsvn_repos-1 -lsvn_client-1 -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

locale_PATH = subversion/po
locale_DEPS =  subversion/po/de.mo subversion/po/es.mo subversion/po/fr.mo subversion/po/it.mo subversion/po/ja.mo subversion/po/ko.mo subversion/po/nb.mo subversion/po/pl.mo subversion/po/pt_BR.mo subversion/po/sv.mo subversion/po/zh_CN.mo subversion/po/zh_TW.mo
locale: $(locale_DEPS)

locks_test_PATH = subversion/tests/libsvn_fs
locks_test_DEPS =  subversion/tests/libsvn_fs/locks-test.o subversion/tests/libsvn_test-1.la
locks_test_OBJECTS = locks-test.o
subversion/tests/libsvn_fs/locks-test$(EXEEXT): $(locks_test_DEPS)
	cd subversion/tests/libsvn_fs && $(LINK) -o locks-test$(EXEEXT)  $(locks_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

mod_authz_svn_PATH = subversion/mod_authz_svn
mod_authz_svn_DEPS =  subversion/mod_authz_svn/mod_authz_svn.lo subversion/mod_dav_svn/mod_dav_svn.la
mod_authz_svn_OBJECTS = mod_authz_svn.lo
subversion/mod_authz_svn/mod_authz_svn.la: $(mod_authz_svn_DEPS)
	cd subversion/mod_authz_svn && $(LINK_APACHE_MOD) -o mod_authz_svn.la $(LT_NO_UNDEFINED) $(mod_authz_svn_OBJECTS) -lsvn_subr-1 -lsvn_repos-1 $(LIBS)

mod_dav_svn_PATH = subversion/mod_dav_svn
mod_dav_svn_DEPS =  subversion/mod_dav_svn/activity.lo subversion/mod_dav_svn/deadprops.lo subversion/mod_dav_svn/file_revs.lo subversion/mod_dav_svn/liveprops.lo subversion/mod_dav_svn/lock.lo subversion/mod_dav_svn/log.lo subversion/mod_dav_svn/merge.lo subversion/mod_dav_svn/mod_dav_svn.lo subversion/mod_dav_svn/replay.lo subversion/mod_dav_svn/repos.lo subversion/mod_dav_svn/update.lo subversion/mod_dav_svn/util.lo subversion/mod_dav_svn/version.lo
mod_dav_svn_OBJECTS = activity.lo deadprops.lo file_revs.lo liveprops.lo lock.lo log.lo merge.lo mod_dav_svn.lo replay.lo repos.lo update.lo util.lo version.lo
subversion/mod_dav_svn/mod_dav_svn.la: $(mod_dav_svn_DEPS)
	cd subversion/mod_dav_svn && $(LINK_APACHE_MOD) -o mod_dav_svn.la $(LT_NO_UNDEFINED) $(mod_dav_svn_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(LIBS)

mucc_PATH = contrib/client-side
mucc_DEPS =  contrib/client-side/mucc.o
mucc_OBJECTS = mucc.o
contrib/client-side/mucc$(EXEEXT): $(mucc_DEPS)
	cd contrib/client-side && $(LINK) -o mucc$(EXEEXT)  $(mucc_OBJECTS) -lsvn_client-1 -lsvn_ra-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

opt_test_PATH = subversion/tests/libsvn_subr
opt_test_DEPS =  subversion/tests/libsvn_subr/opt-test.o subversion/tests/libsvn_test-1.la
opt_test_OBJECTS = opt-test.o
subversion/tests/libsvn_subr/opt-test$(EXEEXT): $(opt_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o opt-test$(EXEEXT)  $(opt_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

path_test_PATH = subversion/tests/libsvn_subr
path_test_DEPS =  subversion/tests/libsvn_subr/path-test.o subversion/tests/libsvn_test-1.la
path_test_OBJECTS = path-test.o
subversion/tests/libsvn_subr/path-test$(EXEEXT): $(path_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o path-test$(EXEEXT)  $(path_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

perl_client_PATH = subversion/bindings/swig/perl/native
perl_client_DEPS =  subversion/bindings/swig/perl/native/svn_client.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_client_OBJECTS = svn_client.lo
subversion/bindings/swig/perl/native/_Client.la: $(perl_client_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Client.la $(LT_NO_UNDEFINED) $(perl_client_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_client-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_core_PATH = subversion/bindings/swig/perl/native
perl_core_DEPS =  subversion/bindings/swig/perl/native/core.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la
perl_core_OBJECTS = core.lo
subversion/bindings/swig/perl/native/_Core.la: $(perl_core_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Core.la $(LT_NO_UNDEFINED) $(perl_core_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_delta_PATH = subversion/bindings/swig/perl/native
perl_delta_DEPS =  subversion/bindings/swig/perl/native/svn_delta.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_delta_OBJECTS = svn_delta.lo
subversion/bindings/swig/perl/native/_Delta.la: $(perl_delta_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Delta.la $(LT_NO_UNDEFINED) $(perl_delta_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_delta-1 -lsvn_subr-1 $(LIBS)

perl_fs_PATH = subversion/bindings/swig/perl/native
perl_fs_DEPS =  subversion/bindings/swig/perl/native/svn_fs.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_fs_OBJECTS = svn_fs.lo
subversion/bindings/swig/perl/native/_Fs.la: $(perl_fs_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Fs.la $(LT_NO_UNDEFINED) $(perl_fs_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_fs-1 -lsvn_subr-1 $(LIBS)

perl_ra_PATH = subversion/bindings/swig/perl/native
perl_ra_DEPS =  subversion/bindings/swig/perl/native/svn_ra.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_ra_OBJECTS = svn_ra.lo
subversion/bindings/swig/perl/native/_Ra.la: $(perl_ra_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Ra.la $(LT_NO_UNDEFINED) $(perl_ra_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_ra-1 -lsvn_subr-1 $(LIBS)

perl_repos_PATH = subversion/bindings/swig/perl/native
perl_repos_DEPS =  subversion/bindings/swig/perl/native/svn_repos.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_repos_OBJECTS = svn_repos.lo
subversion/bindings/swig/perl/native/_Repos.la: $(perl_repos_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Repos.la $(LT_NO_UNDEFINED) $(perl_repos_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_repos-1 -lsvn_subr-1 $(LIBS)

perl_wc_PATH = subversion/bindings/swig/perl/native
perl_wc_DEPS =  subversion/bindings/swig/perl/native/svn_wc.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_wc_OBJECTS = svn_wc.lo
subversion/bindings/swig/perl/native/_Wc.la: $(perl_wc_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Wc.la $(LT_NO_UNDEFINED) $(perl_wc_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_wc-1 -lsvn_subr-1 $(LIBS)

python_client_PATH = subversion/bindings/swig/python
python_client_DEPS =  subversion/bindings/swig/python/svn_client.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_client_OBJECTS = svn_client.lo
subversion/bindings/swig/python/_client.la: $(python_client_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _client.la $(LT_NO_UNDEFINED) $(python_client_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_client-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_core_PATH = subversion/bindings/swig/python
python_core_DEPS =  subversion/bindings/swig/python/core.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la
python_core_OBJECTS = core.lo
subversion/bindings/swig/python/_core.la: $(python_core_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _core.la $(LT_NO_UNDEFINED) $(python_core_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_delta_PATH = subversion/bindings/swig/python
python_delta_DEPS =  subversion/bindings/swig/python/svn_delta.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_delta_OBJECTS = svn_delta.lo
subversion/bindings/swig/python/_delta.la: $(python_delta_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _delta.la $(LT_NO_UNDEFINED) $(python_delta_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_delta-1 -lsvn_subr-1 $(LIBS)

python_fs_PATH = subversion/bindings/swig/python
python_fs_DEPS =  subversion/bindings/swig/python/svn_fs.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_fs_OBJECTS = svn_fs.lo
subversion/bindings/swig/python/_fs.la: $(python_fs_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _fs.la $(LT_NO_UNDEFINED) $(python_fs_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_fs-1 -lsvn_subr-1 $(LIBS)

python_ra_PATH = subversion/bindings/swig/python
python_ra_DEPS =  subversion/bindings/swig/python/svn_ra.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_ra_OBJECTS = svn_ra.lo
subversion/bindings/swig/python/_ra.la: $(python_ra_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _ra.la $(LT_NO_UNDEFINED) $(python_ra_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_ra-1 -lsvn_subr-1 $(LIBS)

python_repos_PATH = subversion/bindings/swig/python
python_repos_DEPS =  subversion/bindings/swig/python/svn_repos.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_repos_OBJECTS = svn_repos.lo
subversion/bindings/swig/python/_repos.la: $(python_repos_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _repos.la $(LT_NO_UNDEFINED) $(python_repos_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_repos-1 -lsvn_subr-1 $(LIBS)

python_wc_PATH = subversion/bindings/swig/python
python_wc_DEPS =  subversion/bindings/swig/python/svn_wc.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_wc_OBJECTS = svn_wc.lo
subversion/bindings/swig/python/_wc.la: $(python_wc_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _wc.la $(LT_NO_UNDEFINED) $(python_wc_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_wc-1 -lsvn_subr-1 $(LIBS)

ra_local_test_PATH = subversion/tests/libsvn_ra_local
ra_local_test_DEPS =  subversion/tests/libsvn_ra_local/ra-local-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_ra_local/libsvn_ra_local-1.la
ra_local_test_OBJECTS = ra-local-test.o
subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT): $(ra_local_test_DEPS)
	cd subversion/tests/libsvn_ra_local && $(LINK) -o ra-local-test$(EXEEXT)  $(ra_local_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la ../../../subversion/libsvn_ra_local/libsvn_ra_local-1.la -lsvn_ra-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

random_test_PATH = subversion/tests/libsvn_delta
random_test_DEPS =  subversion/tests/libsvn_delta/random-test.o subversion/tests/libsvn_test-1.la
random_test_OBJECTS = random-test.o
subversion/tests/libsvn_delta/random-test$(EXEEXT): $(random_test_DEPS)
	cd subversion/tests/libsvn_delta && $(LINK) -o random-test$(EXEEXT)  $(random_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

repos_test_PATH = subversion/tests/libsvn_repos
repos_test_DEPS =  subversion/tests/libsvn_repos/dir-delta-editor.o subversion/tests/libsvn_repos/repos-test.o subversion/tests/libsvn_test-1.la
repos_test_OBJECTS = dir-delta-editor.o repos-test.o
subversion/tests/libsvn_repos/repos-test$(EXEEXT): $(repos_test_DEPS)
	cd subversion/tests/libsvn_repos && $(LINK) -o repos-test$(EXEEXT)  $(repos_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

ruby_client_PATH = subversion/bindings/swig/ruby
ruby_client_DEPS =  subversion/bindings/swig/ruby/svn_client.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_client_OBJECTS = svn_client.lo
subversion/bindings/swig/ruby/client.la: $(ruby_client_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o client.la $(LT_NO_UNDEFINED) $(ruby_client_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_client-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_core_PATH = subversion/bindings/swig/ruby
ruby_core_DEPS =  subversion/bindings/swig/ruby/core.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la
ruby_core_OBJECTS = core.lo
subversion/bindings/swig/ruby/core.la: $(ruby_core_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o core.la $(LT_NO_UNDEFINED) $(ruby_core_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_delta_PATH = subversion/bindings/swig/ruby
ruby_delta_DEPS =  subversion/bindings/swig/ruby/svn_delta.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_delta_OBJECTS = svn_delta.lo
subversion/bindings/swig/ruby/delta.la: $(ruby_delta_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o delta.la $(LT_NO_UNDEFINED) $(ruby_delta_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_delta-1 -lsvn_subr-1 $(LIBS)

ruby_fs_PATH = subversion/bindings/swig/ruby
ruby_fs_DEPS =  subversion/bindings/swig/ruby/svn_fs.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_fs_OBJECTS = svn_fs.lo
subversion/bindings/swig/ruby/fs.la: $(ruby_fs_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o fs.la $(LT_NO_UNDEFINED) $(ruby_fs_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_fs-1 -lsvn_subr-1 $(LIBS)

ruby_ra_PATH = subversion/bindings/swig/ruby
ruby_ra_DEPS =  subversion/bindings/swig/ruby/svn_ra.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_ra_OBJECTS = svn_ra.lo
subversion/bindings/swig/ruby/ra.la: $(ruby_ra_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o ra.la $(LT_NO_UNDEFINED) $(ruby_ra_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_ra-1 -lsvn_subr-1 $(LIBS)

ruby_repos_PATH = subversion/bindings/swig/ruby
ruby_repos_DEPS =  subversion/bindings/swig/ruby/svn_repos.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_repos_OBJECTS = svn_repos.lo
subversion/bindings/swig/ruby/repos.la: $(ruby_repos_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o repos.la $(LT_NO_UNDEFINED) $(ruby_repos_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_repos-1 -lsvn_subr-1 $(LIBS)

ruby_wc_PATH = subversion/bindings/swig/ruby
ruby_wc_DEPS =  subversion/bindings/swig/ruby/svn_wc.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_wc_OBJECTS = svn_wc.lo
subversion/bindings/swig/ruby/wc.la: $(ruby_wc_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o wc.la $(LT_NO_UNDEFINED) $(ruby_wc_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_wc-1 -lsvn_subr-1 $(LIBS)

skel_test_PATH = subversion/tests/libsvn_fs_base
skel_test_DEPS =  subversion/tests/libsvn_fs_base/skel-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la
skel_test_OBJECTS = skel-test.o
subversion/tests/libsvn_fs_base/skel-test$(EXEEXT): $(skel_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o skel-test$(EXEEXT)  $(skel_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

stream_test_PATH = subversion/tests/libsvn_subr
stream_test_DEPS =  subversion/tests/libsvn_subr/stream-test.o subversion/tests/libsvn_test-1.la
stream_test_OBJECTS = stream-test.o
subversion/tests/libsvn_subr/stream-test$(EXEEXT): $(stream_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o stream-test$(EXEEXT)  $(stream_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

string_test_PATH = subversion/tests/libsvn_subr
string_test_DEPS =  subversion/tests/libsvn_subr/string-test.o subversion/tests/libsvn_test-1.la
string_test_OBJECTS = string-test.o
subversion/tests/libsvn_subr/string-test$(EXEEXT): $(string_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o string-test$(EXEEXT)  $(string_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

strings_reps_test_PATH = subversion/tests/libsvn_fs_base
strings_reps_test_DEPS =  subversion/tests/libsvn_fs_base/strings-reps-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la
strings_reps_test_OBJECTS = strings-reps-test.o
subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT): $(strings_reps_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o strings-reps-test$(EXEEXT)  $(strings_reps_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svn_PATH = subversion/svn
svn_DEPS =  subversion/svn/add-cmd.o subversion/svn/blame-cmd.o subversion/svn/cat-cmd.o subversion/svn/checkout-cmd.o subversion/svn/cleanup-cmd.o subversion/svn/commit-cmd.o subversion/svn/copy-cmd.o subversion/svn/delete-cmd.o subversion/svn/diff-cmd.o subversion/svn/export-cmd.o subversion/svn/help-cmd.o subversion/svn/import-cmd.o subversion/svn/info-cmd.o subversion/svn/list-cmd.o subversion/svn/lock-cmd.o subversion/svn/log-cmd.o subversion/svn/main.o subversion/svn/merge-cmd.o subversion/svn/mkdir-cmd.o subversion/svn/move-cmd.o subversion/svn/notify.o subversion/svn/propdel-cmd.o subversion/svn/propedit-cmd.o subversion/svn/propget-cmd.o subversion/svn/proplist-cmd.o subversion/svn/props.o subversion/svn/propset-cmd.o subversion/svn/resolved-cmd.o subversion/svn/revert-cmd.o subversion/svn/status-cmd.o subversion/svn/status.o subversion/svn/switch-cmd.o subversion/svn/unlock-cmd.o subversion/svn/update-cmd.o subversion/svn/util.o
svn_OBJECTS = add-cmd.o blame-cmd.o cat-cmd.o checkout-cmd.o cleanup-cmd.o commit-cmd.o copy-cmd.o delete-cmd.o diff-cmd.o export-cmd.o help-cmd.o import-cmd.o info-cmd.o list-cmd.o lock-cmd.o log-cmd.o main.o merge-cmd.o mkdir-cmd.o move-cmd.o notify.o propdel-cmd.o propedit-cmd.o propget-cmd.o proplist-cmd.o props.o propset-cmd.o resolved-cmd.o revert-cmd.o status-cmd.o status.o switch-cmd.o unlock-cmd.o update-cmd.o util.o
subversion/svn/svn$(EXEEXT): $(svn_DEPS)
	cd subversion/svn && $(LINK) -o svn$(EXEEXT)  $(svn_OBJECTS) -lsvn_client-1 -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

svn_push_PATH = contrib/client-side/svn-push
svn_push_DEPS =  contrib/client-side/svn-push/svn-push.o
svn_push_OBJECTS = svn-push.o
contrib/client-side/svn-push/svn-push$(EXEEXT): $(svn_push_DEPS)
	cd contrib/client-side/svn-push && $(LINK) -o svn-push$(EXEEXT)  $(svn_push_OBJECTS) -lsvn_delta-1 -lsvn_ra-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

svnadmin_PATH = subversion/svnadmin
svnadmin_DEPS =  subversion/svnadmin/main.o
svnadmin_OBJECTS = main.o
subversion/svnadmin/svnadmin$(EXEEXT): $(svnadmin_DEPS)
	cd subversion/svnadmin && $(LINK) -o svnadmin$(EXEEXT)  $(svnadmin_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svnauthz_validate_PATH = tools/server-side
svnauthz_validate_DEPS =  tools/server-side/svnauthz-validate.o
svnauthz_validate_OBJECTS = svnauthz-validate.o
tools/server-side/svnauthz-validate$(EXEEXT): $(svnauthz_validate_DEPS)
	cd tools/server-side && $(LINK) -o svnauthz-validate$(EXEEXT)  $(svnauthz_validate_OBJECTS) -lsvn_repos-1 $(LIBS)

svndiff_test_PATH = subversion/tests/libsvn_delta
svndiff_test_DEPS =  subversion/tests/libsvn_delta/svndiff-test.o
svndiff_test_OBJECTS = svndiff-test.o
subversion/tests/libsvn_delta/svndiff-test$(EXEEXT): $(svndiff_test_DEPS)
	cd subversion/tests/libsvn_delta && $(LINK) -o svndiff-test$(EXEEXT)  $(svndiff_test_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svndumpfilter_PATH = subversion/svndumpfilter
svndumpfilter_DEPS =  subversion/svndumpfilter/main.o
svndumpfilter_OBJECTS = main.o
subversion/svndumpfilter/svndumpfilter$(EXEEXT): $(svndumpfilter_DEPS)
	cd subversion/svndumpfilter && $(LINK) -o svndumpfilter$(EXEEXT)  $(svndumpfilter_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svnlook_PATH = subversion/svnlook
svnlook_DEPS =  subversion/svnlook/main.o
svnlook_OBJECTS = main.o
subversion/svnlook/svnlook$(EXEEXT): $(svnlook_DEPS)
	cd subversion/svnlook && $(LINK) -o svnlook$(EXEEXT)  $(svnlook_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svnserve_PATH = subversion/svnserve
svnserve_DEPS =  subversion/svnserve/main.o subversion/svnserve/serve.o subversion/svnserve/winservice.o subversion/libsvn_ra_svn/libsvn_ra_svn-1.la
svnserve_OBJECTS = main.o serve.o winservice.o
subversion/svnserve/svnserve$(EXEEXT): $(svnserve_DEPS)
	cd subversion/svnserve && $(LINK) -o svnserve$(EXEEXT)  $(svnserve_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 ../../subversion/libsvn_ra_svn/libsvn_ra_svn-1.la $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svnsync_PATH = subversion/svnsync
svnsync_DEPS =  subversion/svnsync/main.o
svnsync_OBJECTS = main.o
subversion/svnsync/svnsync$(EXEEXT): $(svnsync_DEPS)
	cd subversion/svnsync && $(LINK) -o svnsync$(EXEEXT)  $(svnsync_OBJECTS) -lsvn_ra-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

svnversion_PATH = subversion/svnversion
svnversion_DEPS =  subversion/svnversion/main.o
svnversion_OBJECTS = main.o
subversion/svnversion/svnversion$(EXEEXT): $(svnversion_DEPS)
	cd subversion/svnversion && $(LINK) -o svnversion$(EXEEXT)  $(svnversion_OBJECTS) -lsvn_subr-1 -lsvn_wc-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

target_test_PATH = subversion/tests/libsvn_subr
target_test_DEPS =  subversion/tests/libsvn_subr/target-test.o
target_test_OBJECTS = target-test.o
subversion/tests/libsvn_subr/target-test$(EXEEXT): $(target_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o target-test$(EXEEXT)  $(target_test_OBJECTS) -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

time_test_PATH = subversion/tests/libsvn_subr
time_test_DEPS =  subversion/tests/libsvn_subr/time-test.o subversion/tests/libsvn_test-1.la
time_test_OBJECTS = time-test.o
subversion/tests/libsvn_subr/time-test$(EXEEXT): $(time_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o time-test$(EXEEXT)  $(time_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

translate_test_PATH = subversion/tests/libsvn_wc
translate_test_DEPS =  subversion/tests/libsvn_wc/translate-test.o subversion/tests/libsvn_test-1.la
translate_test_OBJECTS = translate-test.o
subversion/tests/libsvn_wc/translate-test$(EXEEXT): $(translate_test_DEPS)
	cd subversion/tests/libsvn_wc && $(LINK) -o translate-test$(EXEEXT)  $(translate_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_delta-1 -lsvn_wc-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

utf_test_PATH = subversion/tests/libsvn_subr
utf_test_DEPS =  subversion/tests/libsvn_subr/utf-test.o subversion/tests/libsvn_test-1.la
utf_test_OBJECTS = utf-test.o
subversion/tests/libsvn_subr/utf-test$(EXEEXT): $(utf_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o utf-test$(EXEEXT)  $(utf_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

vdelta_test_PATH = subversion/tests/libsvn_delta
vdelta_test_DEPS =  subversion/tests/libsvn_delta/vdelta-test.o
vdelta_test_OBJECTS = vdelta-test.o
subversion/tests/libsvn_delta/vdelta-test$(EXEEXT): $(vdelta_test_DEPS)
	cd subversion/tests/libsvn_delta && $(LINK) -o vdelta-test$(EXEEXT)  $(vdelta_test_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)


########################################
# Section 6: Install-Group build targets
########################################

apache-mod: subversion/mod_authz_svn/mod_authz_svn.la subversion/mod_dav_svn/mod_dav_svn.la

bdb-lib: subversion/libsvn_fs_base/libsvn_fs_base-1.la

bdb-test: subversion/tests/libsvn_fs_base/changes-test$(EXEEXT) subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT) subversion/tests/libsvn_fs_base/key-test$(EXEEXT) subversion/tests/libsvn_fs_base/skel-test$(EXEEXT) subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT)

bin: subversion/svn/svn$(EXEEXT) subversion/svnadmin/svnadmin$(EXEEXT) subversion/svndumpfilter/svndumpfilter$(EXEEXT) subversion/svnlook/svnlook$(EXEEXT) subversion/svnserve/svnserve$(EXEEXT) subversion/svnsync/svnsync$(EXEEXT) subversion/svnversion/svnversion$(EXEEXT)

contrib: tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) contrib/client-side/mucc$(EXEEXT) contrib/client-side/svn-push/svn-push$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT)

dav-lib: subversion/libsvn_ra_dav/libsvn_ra_dav-1.la

fsmod-lib: subversion/libsvn_delta/libsvn_delta-1.la subversion/libsvn_fs_fs/libsvn_fs_fs-1.la subversion/libsvn_subr/libsvn_subr-1.la

javahl-java: 

javahl-javah: 

javahl-lib: subversion/bindings/java/javahl/native/libsvnjavahl-1.la

javahl-tests: 

lib: subversion/libsvn_client/libsvn_client-1.la subversion/libsvn_diff/libsvn_diff-1.la subversion/libsvn_ra/libsvn_ra-1.la subversion/libsvn_wc/libsvn_wc-1.la

locale: 

ramod-lib: subversion/libsvn_fs/libsvn_fs-1.la subversion/libsvn_ra_local/libsvn_ra_local-1.la subversion/libsvn_ra_svn/libsvn_ra_svn-1.la subversion/libsvn_repos/libsvn_repos-1.la

serf-lib: subversion/libsvn_ra_serf/libsvn_ra_serf-1.la

swig-pl-lib: subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la

swig-py: subversion/bindings/swig/python/_client.la subversion/bindings/swig/python/_core.la subversion/bindings/swig/python/_delta.la subversion/bindings/swig/python/_fs.la subversion/bindings/swig/python/_ra.la subversion/bindings/swig/python/_repos.la subversion/bindings/swig/python/_wc.la

swig-py-lib: subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la

swig-rb: subversion/bindings/swig/ruby/client.la subversion/bindings/swig/ruby/core.la subversion/bindings/swig/ruby/delta.la subversion/bindings/swig/ruby/fs.la subversion/bindings/swig/ruby/ra.la subversion/bindings/swig/ruby/repos.la subversion/bindings/swig/ruby/wc.la

swig-rb-lib: subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la

test: subversion/tests/libsvn_subr/compat-test$(EXEEXT) subversion/tests/libsvn_subr/config-test$(EXEEXT) subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT) subversion/tests/libsvn_fs/fs-test$(EXEEXT) subversion/tests/libsvn_subr/hashdump-test$(EXEEXT) subversion/tests/libsvn_test-1.la subversion/tests/libsvn_fs/locks-test$(EXEEXT) subversion/tests/libsvn_subr/opt-test$(EXEEXT) subversion/tests/libsvn_subr/path-test$(EXEEXT) subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT) subversion/tests/libsvn_delta/random-test$(EXEEXT) subversion/tests/libsvn_repos/repos-test$(EXEEXT) subversion/tests/libsvn_subr/stream-test$(EXEEXT) subversion/tests/libsvn_subr/string-test$(EXEEXT) subversion/tests/libsvn_delta/svndiff-test$(EXEEXT) subversion/tests/libsvn_subr/target-test$(EXEEXT) subversion/tests/libsvn_subr/time-test$(EXEEXT) subversion/tests/libsvn_wc/translate-test$(EXEEXT) subversion/tests/libsvn_subr/utf-test$(EXEEXT) subversion/tests/libsvn_delta/vdelta-test$(EXEEXT)


########################################
# Section 7: Install-Group install targets
########################################

install-mods-shared: subversion/mod_dav_svn/mod_dav_svn.la subversion/mod_authz_svn/mod_authz_svn.la
	cd subversion/mod_dav_svn ; $(MKDIR) "$(APACHE_LIBEXECDIR)" ; $(INSTALL_MOD_SHARED) -n dav_svn mod_dav_svn.la
	cd subversion/mod_authz_svn ; $(MKDIR) "$(APACHE_LIBEXECDIR)" ; $(INSTALL_MOD_SHARED) -n authz_svn mod_authz_svn.la

install-mods-static: subversion/libsvn_delta/libsvn_delta-1.la-a subversion/libsvn_fs/libsvn_fs-1.la-a subversion/libsvn_repos/libsvn_repos-1.la-a subversion/libsvn_subr/libsvn_subr-1.la-a subversion/mod_authz_svn/mod_authz_svn.la-a subversion/mod_dav_svn/mod_dav_svn.la-a subversion/mod_dav_svn/static/Makefile.in subversion/mod_dav_svn/static/config.m4
	$(MKDIR) $(DESTDIR)$(APACHE_TARGET)/.libs
	$(INSTALL_MOD_STATIC) subversion/libsvn_delta/.libs/libsvn_delta-1.a $(DESTDIR)$(APACHE_TARGET)/.libs/libsvn_delta-1.a
	$(INSTALL_MOD_STATIC) subversion/libsvn_delta/libsvn_delta-1.la-a $(DESTDIR)$(APACHE_TARGET)/libsvn_delta-1.la
	$(INSTALL_MOD_STATIC) subversion/libsvn_fs/.libs/libsvn_fs-1.a $(DESTDIR)$(APACHE_TARGET)/.libs/libsvn_fs-1.a
	$(INSTALL_MOD_STATIC) subversion/libsvn_fs/libsvn_fs-1.la-a $(DESTDIR)$(APACHE_TARGET)/libsvn_fs-1.la
	$(INSTALL_MOD_STATIC) subversion/libsvn_repos/.libs/libsvn_repos-1.a $(DESTDIR)$(APACHE_TARGET)/.libs/libsvn_repos-1.a
	$(INSTALL_MOD_STATIC) subversion/libsvn_repos/libsvn_repos-1.la-a $(DESTDIR)$(APACHE_TARGET)/libsvn_repos-1.la
	$(INSTALL_MOD_STATIC) subversion/libsvn_subr/.libs/libsvn_subr-1.a $(DESTDIR)$(APACHE_TARGET)/.libs/libsvn_subr-1.a
	$(INSTALL_MOD_STATIC) subversion/libsvn_subr/libsvn_subr-1.la-a $(DESTDIR)$(APACHE_TARGET)/libsvn_subr-1.la
	$(INSTALL_MOD_STATIC) subversion/mod_authz_svn/.libs/mod_authz_svn.a $(DESTDIR)$(APACHE_TARGET)/.libs/mod_authz_svn.a
	$(INSTALL_MOD_STATIC) subversion/mod_authz_svn/mod_authz_svn.la-a $(DESTDIR)$(APACHE_TARGET)/mod_authz_svn.la
	$(INSTALL_MOD_STATIC) subversion/mod_dav_svn/.libs/mod_dav_svn.a $(DESTDIR)$(APACHE_TARGET)/.libs/mod_dav_svn.a
	$(INSTALL_MOD_STATIC) subversion/mod_dav_svn/mod_dav_svn.la-a $(DESTDIR)$(APACHE_TARGET)/mod_dav_svn.la
	$(INSTALL_MOD_STATIC) subversion/mod_dav_svn/static/Makefile.in $(DESTDIR)$(APACHE_TARGET)/Makefile.in
	$(INSTALL_MOD_STATIC) subversion/mod_dav_svn/static/config.m4 $(DESTDIR)$(APACHE_TARGET)/config.m4

install-bdb-lib: subversion/libsvn_fs_base/libsvn_fs_base-1.la
	$(MKDIR) $(DESTDIR)$(bdb_libdir)
	cd subversion/libsvn_fs_base ; $(INSTALL_BDB_LIB) libsvn_fs_base-1.la $(DESTDIR)$(bdb_libdir)/libsvn_fs_base-1.la

install-bin: subversion/svn/svn$(EXEEXT) subversion/svnadmin/svnadmin$(EXEEXT) subversion/svndumpfilter/svndumpfilter$(EXEEXT) subversion/svnlook/svnlook$(EXEEXT) subversion/svnserve/svnserve$(EXEEXT) subversion/svnsync/svnsync$(EXEEXT) subversion/svnversion/svnversion$(EXEEXT)
	$(MKDIR) $(DESTDIR)$(bindir)
	cd subversion/svn ; $(INSTALL_BIN) svn$(EXEEXT) $(DESTDIR)$(bindir)/svn$(EXEEXT)
	cd subversion/svnadmin ; $(INSTALL_BIN) svnadmin$(EXEEXT) $(DESTDIR)$(bindir)/svnadmin$(EXEEXT)
	cd subversion/svndumpfilter ; $(INSTALL_BIN) svndumpfilter$(EXEEXT) $(DESTDIR)$(bindir)/svndumpfilter$(EXEEXT)
	cd subversion/svnlook ; $(INSTALL_BIN) svnlook$(EXEEXT) $(DESTDIR)$(bindir)/svnlook$(EXEEXT)
	cd subversion/svnserve ; $(INSTALL_BIN) svnserve$(EXEEXT) $(DESTDIR)$(bindir)/svnserve$(EXEEXT)
	cd subversion/svnsync ; $(INSTALL_BIN) svnsync$(EXEEXT) $(DESTDIR)$(bindir)/svnsync$(EXEEXT)
	cd subversion/svnversion ; $(INSTALL_BIN) svnversion$(EXEEXT) $(DESTDIR)$(bindir)/svnversion$(EXEEXT)

install-contrib: tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) contrib/client-side/mucc$(EXEEXT) contrib/client-side/svn-push/svn-push$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT)
	$(MKDIR) $(DESTDIR)$(contribdir)
	cd tools/diff ; $(INSTALL_CONTRIB) diff$(EXEEXT) $(DESTDIR)$(contribdir)/diff$(EXEEXT)
	cd tools/diff ; $(INSTALL_CONTRIB) diff3$(EXEEXT) $(DESTDIR)$(contribdir)/diff3$(EXEEXT)
	cd tools/diff ; $(INSTALL_CONTRIB) diff4$(EXEEXT) $(DESTDIR)$(contribdir)/diff4$(EXEEXT)
	cd contrib/client-side ; $(INSTALL_CONTRIB) mucc$(EXEEXT) $(DESTDIR)$(contribdir)/mucc$(EXEEXT)
	cd contrib/client-side/svn-push ; $(INSTALL_CONTRIB) svn-push$(EXEEXT) $(DESTDIR)$(contribdir)/svn-push$(EXEEXT)
	cd tools/server-side ; $(INSTALL_CONTRIB) svnauthz-validate$(EXEEXT) $(DESTDIR)$(contribdir)/svnauthz-validate$(EXEEXT)

install-dav-lib: subversion/libsvn_ra_dav/libsvn_ra_dav-1.la
	$(MKDIR) $(DESTDIR)$(dav_libdir)
	cd subversion/libsvn_ra_dav ; $(INSTALL_DAV_LIB) libsvn_ra_dav-1.la $(DESTDIR)$(dav_libdir)/libsvn_ra_dav-1.la

install-fsmod-lib: subversion/libsvn_subr/libsvn_subr-1.la subversion/libsvn_delta/libsvn_delta-1.la subversion/libsvn_fs_fs/libsvn_fs_fs-1.la
	$(MKDIR) $(DESTDIR)$(fsmod_libdir)
	cd subversion/libsvn_subr ; $(INSTALL_FSMOD_LIB) libsvn_subr-1.la $(DESTDIR)$(fsmod_libdir)/libsvn_subr-1.la
	cd subversion/libsvn_delta ; $(INSTALL_FSMOD_LIB) libsvn_delta-1.la $(DESTDIR)$(fsmod_libdir)/libsvn_delta-1.la
	cd subversion/libsvn_fs_fs ; $(INSTALL_FSMOD_LIB) libsvn_fs_fs-1.la $(DESTDIR)$(fsmod_libdir)/libsvn_fs_fs-1.la

install-javahl-java: 
	$(MKDIR) $(DESTDIR)$(javahl_javadir)
	$(INSTALL_EXTRA_JAVAHL_JAVA)

install-javahl-javah: 
	$(MKDIR) $(DESTDIR)$(javahl_javahdir)
	$(INSTALL_EXTRA_JAVAHL_JAVAH)

install-javahl-lib: subversion/bindings/java/javahl/native/libsvnjavahl-1.la
	$(MKDIR) $(DESTDIR)$(javahl_libdir)
	cd subversion/bindings/java/javahl/native ; $(INSTALL_JAVAHL_LIB) libsvnjavahl-1.la $(DESTDIR)$(javahl_libdir)/libsvnjavahl-1.la
	$(INSTALL_EXTRA_JAVAHL_LIB)

install-javahl-tests: 
	$(MKDIR) $(DESTDIR)$(javahl_testsdir)
	$(INSTALL_EXTRA_JAVAHL_TESTS)

install-lib: subversion/libsvn_diff/libsvn_diff-1.la subversion/libsvn_ra/libsvn_ra-1.la subversion/libsvn_wc/libsvn_wc-1.la subversion/libsvn_client/libsvn_client-1.la
	$(MKDIR) $(DESTDIR)$(libdir)
	cd subversion/libsvn_diff ; $(INSTALL_LIB) libsvn_diff-1.la $(DESTDIR)$(libdir)/libsvn_diff-1.la
	cd subversion/libsvn_ra ; $(INSTALL_LIB) libsvn_ra-1.la $(DESTDIR)$(libdir)/libsvn_ra-1.la
	cd subversion/libsvn_wc ; $(INSTALL_LIB) libsvn_wc-1.la $(DESTDIR)$(libdir)/libsvn_wc-1.la
	cd subversion/libsvn_client ; $(INSTALL_LIB) libsvn_client-1.la $(DESTDIR)$(libdir)/libsvn_client-1.la

install-locale: subversion/po/de.mo subversion/po/es.mo subversion/po/fr.mo subversion/po/it.mo subversion/po/ja.mo subversion/po/ko.mo subversion/po/nb.mo subversion/po/pl.mo subversion/po/pt_BR.mo subversion/po/sv.mo subversion/po/zh_CN.mo subversion/po/zh_TW.mo
	$(MKDIR) $(DESTDIR)$(localedir)
	$(MKDIR) $(DESTDIR)$(localedir)/de/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) de.mo $(DESTDIR)$(localedir)/de/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/es/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) es.mo $(DESTDIR)$(localedir)/es/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/fr/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) fr.mo $(DESTDIR)$(localedir)/fr/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/it/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) it.mo $(DESTDIR)$(localedir)/it/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/ja/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) ja.mo $(DESTDIR)$(localedir)/ja/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/ko/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) ko.mo $(DESTDIR)$(localedir)/ko/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/nb/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) nb.mo $(DESTDIR)$(localedir)/nb/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/pl/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) pl.mo $(DESTDIR)$(localedir)/pl/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/pt_BR/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) pt_BR.mo $(DESTDIR)$(localedir)/pt_BR/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/sv/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) sv.mo $(DESTDIR)$(localedir)/sv/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/zh_CN/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) zh_CN.mo $(DESTDIR)$(localedir)/zh_CN/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/zh_TW/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) zh_TW.mo $(DESTDIR)$(localedir)/zh_TW/LC_MESSAGES/$(PACKAGE_NAME).mo

install-ramod-lib: subversion/libsvn_fs/libsvn_fs-1.la subversion/libsvn_ra_svn/libsvn_ra_svn-1.la subversion/libsvn_repos/libsvn_repos-1.la subversion/libsvn_ra_local/libsvn_ra_local-1.la
	$(MKDIR) $(DESTDIR)$(ramod_libdir)
	cd subversion/libsvn_fs ; $(INSTALL_RAMOD_LIB) libsvn_fs-1.la $(DESTDIR)$(ramod_libdir)/libsvn_fs-1.la
	cd subversion/libsvn_ra_svn ; $(INSTALL_RAMOD_LIB) libsvn_ra_svn-1.la $(DESTDIR)$(ramod_libdir)/libsvn_ra_svn-1.la
	cd subversion/libsvn_repos ; $(INSTALL_RAMOD_LIB) libsvn_repos-1.la $(DESTDIR)$(ramod_libdir)/libsvn_repos-1.la
	cd subversion/libsvn_ra_local ; $(INSTALL_RAMOD_LIB) libsvn_ra_local-1.la $(DESTDIR)$(ramod_libdir)/libsvn_ra_local-1.la

install-serf-lib: subversion/libsvn_ra_serf/libsvn_ra_serf-1.la
	$(MKDIR) $(DESTDIR)$(serf_libdir)
	cd subversion/libsvn_ra_serf ; $(INSTALL_SERF_LIB) libsvn_ra_serf-1.la $(DESTDIR)$(serf_libdir)/libsvn_ra_serf-1.la

install-swig-pl-lib: subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la
	$(MKDIR) $(DESTDIR)$(swig_pl_libdir)
	cd subversion/bindings/swig/perl/libsvn_swig_perl ; $(INSTALL_SWIG_PL_LIB) libsvn_swig_perl-1.la $(DESTDIR)$(swig_pl_libdir)/libsvn_swig_perl-1.la

install-swig-py: subversion/bindings/swig/python/_core.la subversion/bindings/swig/python/_client.la subversion/bindings/swig/python/_delta.la subversion/bindings/swig/python/_fs.la subversion/bindings/swig/python/_ra.la subversion/bindings/swig/python/_repos.la subversion/bindings/swig/python/_wc.la
	$(MKDIR) $(DESTDIR)$(swig_pydir)
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _core.la $(DESTDIR)$(swig_pydir)/_core.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _client.la $(DESTDIR)$(swig_pydir)/_client.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _delta.la $(DESTDIR)$(swig_pydir)/_delta.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _fs.la $(DESTDIR)$(swig_pydir)/_fs.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _ra.la $(DESTDIR)$(swig_pydir)/_ra.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _repos.la $(DESTDIR)$(swig_pydir)/_repos.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _wc.la $(DESTDIR)$(swig_pydir)/_wc.la
	$(INSTALL_EXTRA_SWIG_PY)

install-swig-py-lib: subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la
	$(MKDIR) $(DESTDIR)$(swig_py_libdir)
	cd subversion/bindings/swig/python/libsvn_swig_py ; $(INSTALL_SWIG_PY_LIB) libsvn_swig_py-1.la $(DESTDIR)$(swig_py_libdir)/libsvn_swig_py-1.la

install-swig-rb: subversion/bindings/swig/ruby/core.la subversion/bindings/swig/ruby/client.la subversion/bindings/swig/ruby/delta.la subversion/bindings/swig/ruby/fs.la subversion/bindings/swig/ruby/ra.la subversion/bindings/swig/ruby/repos.la subversion/bindings/swig/ruby/wc.la
	$(MKDIR) $(DESTDIR)$(swig_rbdir)
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) core.la $(DESTDIR)$(swig_rbdir)/core.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) client.la $(DESTDIR)$(swig_rbdir)/client.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) delta.la $(DESTDIR)$(swig_rbdir)/delta.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) fs.la $(DESTDIR)$(swig_rbdir)/fs.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) ra.la $(DESTDIR)$(swig_rbdir)/ra.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) repos.la $(DESTDIR)$(swig_rbdir)/repos.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) wc.la $(DESTDIR)$(swig_rbdir)/wc.la
	$(INSTALL_EXTRA_SWIG_RB)

install-swig-rb-lib: subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la
	$(MKDIR) $(DESTDIR)$(swig_rb_libdir)
	cd subversion/bindings/swig/ruby/libsvn_swig_ruby ; $(INSTALL_SWIG_RB_LIB) libsvn_swig_ruby-1.la $(DESTDIR)$(swig_rb_libdir)/libsvn_swig_ruby-1.la


########################################
# Section 8: The install-include rule
########################################

install-include: subversion/include/svn_cmdline.h subversion/include/svn_version.h subversion/include/svn_sorts.h subversion/include/svn_nls.h subversion/include/svn_base64.h subversion/include/mod_dav_svn.h subversion/include/svn_error_codes.h subversion/include/svn_time.h subversion/include/svn_quoprint.h subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_types.h subversion/include/svn_props.h subversion/include/svn_path.h subversion/include/svn_delta.h subversion/include/svn_dav.h subversion/include/svn_error.h subversion/include/svn_user.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_dso.h subversion/include/svn_io.h subversion/include/svn_client.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_xml.h subversion/include/svn_diff.h subversion/include/svn_pools.h subversion/include/svn_subst.h subversion/include/svn_hash.h subversion/include/svn_opt.h subversion/include/svn_wc.h subversion/include/svn_utf.h subversion/include/svn_md5.h subversion/include/svn_ra_svn.h subversion/include/svn_ctype.h
	$(MKDIR) $(DESTDIR)$(includedir)/subversion-1
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_cmdline.h $(DESTDIR)$(includedir)/subversion-1/svn_cmdline.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_version.h $(DESTDIR)$(includedir)/subversion-1/svn_version.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_sorts.h $(DESTDIR)$(includedir)/subversion-1/svn_sorts.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_nls.h $(DESTDIR)$(includedir)/subversion-1/svn_nls.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_base64.h $(DESTDIR)$(includedir)/subversion-1/svn_base64.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/mod_dav_svn.h $(DESTDIR)$(includedir)/subversion-1/mod_dav_svn.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_error_codes.h $(DESTDIR)$(includedir)/subversion-1/svn_error_codes.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_time.h $(DESTDIR)$(includedir)/subversion-1/svn_time.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_quoprint.h $(DESTDIR)$(includedir)/subversion-1/svn_quoprint.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_auth.h $(DESTDIR)$(includedir)/subversion-1/svn_auth.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_config.h $(DESTDIR)$(includedir)/subversion-1/svn_config.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_types.h $(DESTDIR)$(includedir)/subversion-1/svn_types.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_props.h $(DESTDIR)$(includedir)/subversion-1/svn_props.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_path.h $(DESTDIR)$(includedir)/subversion-1/svn_path.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_delta.h $(DESTDIR)$(includedir)/subversion-1/svn_delta.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_dav.h $(DESTDIR)$(includedir)/subversion-1/svn_dav.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_error.h $(DESTDIR)$(includedir)/subversion-1/svn_error.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_user.h $(DESTDIR)$(includedir)/subversion-1/svn_user.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_fs.h $(DESTDIR)$(includedir)/subversion-1/svn_fs.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_ra.h $(DESTDIR)$(includedir)/subversion-1/svn_ra.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_dso.h $(DESTDIR)$(includedir)/subversion-1/svn_dso.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_io.h $(DESTDIR)$(includedir)/subversion-1/svn_io.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_client.h $(DESTDIR)$(includedir)/subversion-1/svn_client.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_repos.h $(DESTDIR)$(includedir)/subversion-1/svn_repos.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_string.h $(DESTDIR)$(includedir)/subversion-1/svn_string.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_xml.h $(DESTDIR)$(includedir)/subversion-1/svn_xml.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_diff.h $(DESTDIR)$(includedir)/subversion-1/svn_diff.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_pools.h $(DESTDIR)$(includedir)/subversion-1/svn_pools.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_subst.h $(DESTDIR)$(includedir)/subversion-1/svn_subst.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_hash.h $(DESTDIR)$(includedir)/subversion-1/svn_hash.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_opt.h $(DESTDIR)$(includedir)/subversion-1/svn_opt.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_wc.h $(DESTDIR)$(includedir)/subversion-1/svn_wc.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_utf.h $(DESTDIR)$(includedir)/subversion-1/svn_utf.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_md5.h $(DESTDIR)$(includedir)/subversion-1/svn_md5.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_ra_svn.h $(DESTDIR)$(includedir)/subversion-1/svn_ra_svn.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_ctype.h $(DESTDIR)$(includedir)/subversion-1/svn_ctype.h

########################################
# Section 9: Shortcut targets for manual builds of specific items
########################################

changes-test: subversion/tests/libsvn_fs_base/changes-test$(EXEEXT)
compat-test: subversion/tests/libsvn_subr/compat-test$(EXEEXT)
config-test: subversion/tests/libsvn_subr/config-test$(EXEEXT)
diff: tools/diff/diff$(EXEEXT)
diff-diff3-test: subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT)
diff3: tools/diff/diff3$(EXEEXT)
diff4: tools/diff/diff4$(EXEEXT)
fs-base-test: subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT)
fs-test: subversion/tests/libsvn_fs/fs-test$(EXEEXT)
hashdump-test: subversion/tests/libsvn_subr/hashdump-test$(EXEEXT)
key-test: subversion/tests/libsvn_fs_base/key-test$(EXEEXT)
libsvn_client: subversion/libsvn_client/libsvn_client-1.la
libsvn_delta: subversion/libsvn_delta/libsvn_delta-1.la
libsvn_diff: subversion/libsvn_diff/libsvn_diff-1.la
libsvn_fs: subversion/libsvn_fs/libsvn_fs-1.la
libsvn_fs_base: subversion/libsvn_fs_base/libsvn_fs_base-1.la
libsvn_fs_fs: subversion/libsvn_fs_fs/libsvn_fs_fs-1.la
libsvn_ra: subversion/libsvn_ra/libsvn_ra-1.la
libsvn_ra_dav: subversion/libsvn_ra_dav/libsvn_ra_dav-1.la
libsvn_ra_local: subversion/libsvn_ra_local/libsvn_ra_local-1.la
libsvn_ra_serf: subversion/libsvn_ra_serf/libsvn_ra_serf-1.la
libsvn_ra_svn: subversion/libsvn_ra_svn/libsvn_ra_svn-1.la
libsvn_repos: subversion/libsvn_repos/libsvn_repos-1.la
libsvn_subr: subversion/libsvn_subr/libsvn_subr-1.la
libsvn_swig_perl: subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la
libsvn_swig_py: subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la
libsvn_swig_ruby: subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la
libsvn_test: subversion/tests/libsvn_test-1.la
libsvn_wc: subversion/libsvn_wc/libsvn_wc-1.la
libsvnjavahl: subversion/bindings/java/javahl/native/libsvnjavahl-1.la
locks-test: subversion/tests/libsvn_fs/locks-test$(EXEEXT)
mod_authz_svn: subversion/mod_authz_svn/mod_authz_svn.la
mod_dav_svn: subversion/mod_dav_svn/mod_dav_svn.la
mucc: contrib/client-side/mucc$(EXEEXT)
opt-test: subversion/tests/libsvn_subr/opt-test$(EXEEXT)
path-test: subversion/tests/libsvn_subr/path-test$(EXEEXT)
perl_client: subversion/bindings/swig/perl/native/_Client.la
perl_core: subversion/bindings/swig/perl/native/_Core.la
perl_delta: subversion/bindings/swig/perl/native/_Delta.la
perl_fs: subversion/bindings/swig/perl/native/_Fs.la
perl_ra: subversion/bindings/swig/perl/native/_Ra.la
perl_repos: subversion/bindings/swig/perl/native/_Repos.la
perl_wc: subversion/bindings/swig/perl/native/_Wc.la
python_client: subversion/bindings/swig/python/_client.la
python_core: subversion/bindings/swig/python/_core.la
python_delta: subversion/bindings/swig/python/_delta.la
python_fs: subversion/bindings/swig/python/_fs.la
python_ra: subversion/bindings/swig/python/_ra.la
python_repos: subversion/bindings/swig/python/_repos.la
python_wc: subversion/bindings/swig/python/_wc.la
ra-local-test: subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT)
random-test: subversion/tests/libsvn_delta/random-test$(EXEEXT)
repos-test: subversion/tests/libsvn_repos/repos-test$(EXEEXT)
ruby_client: subversion/bindings/swig/ruby/client.la
ruby_core: subversion/bindings/swig/ruby/core.la
ruby_delta: subversion/bindings/swig/ruby/delta.la
ruby_fs: subversion/bindings/swig/ruby/fs.la
ruby_ra: subversion/bindings/swig/ruby/ra.la
ruby_repos: subversion/bindings/swig/ruby/repos.la
ruby_wc: subversion/bindings/swig/ruby/wc.la
skel-test: subversion/tests/libsvn_fs_base/skel-test$(EXEEXT)
stream-test: subversion/tests/libsvn_subr/stream-test$(EXEEXT)
string-test: subversion/tests/libsvn_subr/string-test$(EXEEXT)
strings-reps-test: subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT)
svn: subversion/svn/svn$(EXEEXT)
svn-push: contrib/client-side/svn-push/svn-push$(EXEEXT)
svnadmin: subversion/svnadmin/svnadmin$(EXEEXT)
svnauthz-validate: tools/server-side/svnauthz-validate$(EXEEXT)
svndiff-test: subversion/tests/libsvn_delta/svndiff-test$(EXEEXT)
svndumpfilter: subversion/svndumpfilter/svndumpfilter$(EXEEXT)
svnlook: subversion/svnlook/svnlook$(EXEEXT)
svnserve: subversion/svnserve/svnserve$(EXEEXT)
svnsync: subversion/svnsync/svnsync$(EXEEXT)
svnversion: subversion/svnversion/svnversion$(EXEEXT)
target-test: subversion/tests/libsvn_subr/target-test$(EXEEXT)
time-test: subversion/tests/libsvn_subr/time-test$(EXEEXT)
translate-test: subversion/tests/libsvn_wc/translate-test$(EXEEXT)
utf-test: subversion/tests/libsvn_subr/utf-test$(EXEEXT)
vdelta-test: subversion/tests/libsvn_delta/vdelta-test$(EXEEXT)

########################################
# Section 10: Rules to build all other kinds of object-like files
########################################

contrib/client-side/mucc.o: contrib/client-side/mucc.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h

contrib/client-side/svn-push/svn-push.o: contrib/client-side/svn-push/svn-push.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/BlameCallback.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/BlameCallback.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ChangePath.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/ChangePath.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ClientException.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/ClientException.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitItem.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/CommitItem.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitItemStateFlags.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/CommitItemStateFlags.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitMessage.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/CommitMessage.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/DirEntry.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/DirEntry.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Info.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Info.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Info2.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Info2.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/InputInterface.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/InputInterface.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/JNIError.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/JNIError.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Lock.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Lock.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/LockStatus.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/LockStatus.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/LogMessage.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/LogMessage.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NativeResources.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NativeResources.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NodeKind.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NodeKind.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Notify.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Notify.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Notify2.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Notify2.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyAction.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NotifyAction.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyInformation.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NotifyInformation.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyStatus.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/NotifyStatus.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/OutputInterface.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/OutputInterface.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Path.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Path.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/PromptUserPassword.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword2.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/PromptUserPassword2.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword3.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/PromptUserPassword3.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PropertyData.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/PropertyData.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Revision.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Revision.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/RevisionKind.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/RevisionKind.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNAdmin.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNAdmin.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClient.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNClient.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientInterface.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNClientInterface.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientLogLevel.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNClientLogLevel.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientSynchronized.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNClientSynchronized.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNInputStream.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNInputStream.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNOutputStream.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/SVNOutputStream.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ScheduleKind.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/ScheduleKind.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Status.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Status.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/StatusKind.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/StatusKind.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Version.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/Version.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/tests/BasicTests.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests/BasicTests.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/tests/SVNAdminTests.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests/SVNAdminTests.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/tests/SVNTests.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests/SVNTests.java

subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/tests/WC.class: subversion/bindings/java/javahl/src/org/tigris/subversion/javahl/tests/WC.java

subversion/bindings/java/javahl/include/BlameCallback.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/BlameCallback.class

subversion/bindings/java/javahl/include/ChangePath.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ChangePath.class

subversion/bindings/java/javahl/include/ClientException.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ClientException.class

subversion/bindings/java/javahl/include/CommitItem.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitItem.class

subversion/bindings/java/javahl/include/CommitItemStateFlags.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitItemStateFlags.class

subversion/bindings/java/javahl/include/CommitMessage.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/CommitMessage.class

subversion/bindings/java/javahl/include/DirEntry.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/DirEntry.class

subversion/bindings/java/javahl/include/Info.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Info.class

subversion/bindings/java/javahl/include/Info2.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Info2.class

subversion/bindings/java/javahl/include/InputInterface.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/InputInterface.class

subversion/bindings/java/javahl/include/JNIError.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/JNIError.class

subversion/bindings/java/javahl/include/Lock.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Lock.class

subversion/bindings/java/javahl/include/LockStatus.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/LockStatus.class

subversion/bindings/java/javahl/include/LogMessage.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/LogMessage.class

subversion/bindings/java/javahl/include/NativeResources.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NativeResources.class

subversion/bindings/java/javahl/include/NodeKind.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NodeKind.class

subversion/bindings/java/javahl/include/Notify.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Notify.class

subversion/bindings/java/javahl/include/Notify2.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Notify2.class

subversion/bindings/java/javahl/include/NotifyAction.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyAction.class

subversion/bindings/java/javahl/include/NotifyInformation.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyInformation.class

subversion/bindings/java/javahl/include/NotifyStatus.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/NotifyStatus.class

subversion/bindings/java/javahl/include/OutputInterface.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/OutputInterface.class

subversion/bindings/java/javahl/include/Path.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Path.class

subversion/bindings/java/javahl/include/PromptUserPassword.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword.class

subversion/bindings/java/javahl/include/PromptUserPassword2.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword2.class

subversion/bindings/java/javahl/include/PromptUserPassword3.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword3.class

subversion/bindings/java/javahl/include/PropertyData.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/PropertyData.class

subversion/bindings/java/javahl/include/Revision.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Revision.class

subversion/bindings/java/javahl/include/RevisionKind.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/RevisionKind.class

subversion/bindings/java/javahl/include/SVNAdmin.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNAdmin.class

subversion/bindings/java/javahl/include/SVNClient.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClient.class

subversion/bindings/java/javahl/include/SVNClientInterface.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientInterface.class

subversion/bindings/java/javahl/include/SVNClientLogLevel.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientLogLevel.class

subversion/bindings/java/javahl/include/SVNClientSynchronized.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNClientSynchronized.class

subversion/bindings/java/javahl/include/SVNInputStream.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNInputStream.class

subversion/bindings/java/javahl/include/SVNOutputStream.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/SVNOutputStream.class

subversion/bindings/java/javahl/include/ScheduleKind.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/ScheduleKind.class

subversion/bindings/java/javahl/include/Status.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Status.class

subversion/bindings/java/javahl/include/StatusKind.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/StatusKind.class

subversion/bindings/java/javahl/include/Version.h: subversion/bindings/java/javahl/classes/org/tigris/subversion/javahl/Version.class

subversion/bindings/java/javahl/native/BlameCallback.lo: subversion/bindings/java/javahl/native/BlameCallback.cpp subversion/bindings/java/javahl/native/BlameCallback.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/BlameCallback.cpp

subversion/bindings/java/javahl/native/CommitMessage.lo: subversion/bindings/java/javahl/native/CommitMessage.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_CommitItemStateFlags.h subversion/bindings/java/javahl/native/CommitMessage.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/CommitMessage.cpp

subversion/bindings/java/javahl/native/EnumMapper.lo: subversion/bindings/java/javahl/native/EnumMapper.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_CommitItemStateFlags.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_LockStatus.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NodeKind.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NotifyAction.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NotifyStatus.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Revision.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_ScheduleKind.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_StatusKind.h subversion/bindings/java/javahl/native/EnumMapper.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/EnumMapper.cpp

subversion/bindings/java/javahl/native/Inputer.lo: subversion/bindings/java/javahl/native/Inputer.cpp subversion/bindings/java/javahl/native/Inputer.h subversion/bindings/java/javahl/native/JNIByteArray.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Pool.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Inputer.cpp

subversion/bindings/java/javahl/native/JNIByteArray.lo: subversion/bindings/java/javahl/native/JNIByteArray.cpp subversion/bindings/java/javahl/native/JNIByteArray.h subversion/bindings/java/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/JNIByteArray.cpp

subversion/bindings/java/javahl/native/JNICriticalSection.lo: subversion/bindings/java/javahl/native/JNICriticalSection.cpp subversion/bindings/java/javahl/native/JNICriticalSection.h subversion/bindings/java/javahl/native/JNIMutex.h subversion/bindings/java/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/JNICriticalSection.cpp

subversion/bindings/java/javahl/native/JNIMutex.lo: subversion/bindings/java/javahl/native/JNIMutex.cpp subversion/bindings/java/javahl/native/JNIMutex.h subversion/bindings/java/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/JNIMutex.cpp

subversion/bindings/java/javahl/native/JNIStackElement.lo: subversion/bindings/java/javahl/native/JNIStackElement.cpp subversion/bindings/java/javahl/native/JNIStackElement.h subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIThreadData.h subversion/bindings/java/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/JNIStackElement.cpp

subversion/bindings/java/javahl/native/JNIStringHolder.lo: subversion/bindings/java/javahl/native/JNIStringHolder.cpp subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/JNIStringHolder.cpp

subversion/bindings/java/javahl/native/JNIThreadData.lo: subversion/bindings/java/javahl/native/JNIThreadData.cpp subversion/bindings/java/javahl/native/JNIThreadData.h subversion/bindings/java/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/JNIThreadData.cpp

subversion/bindings/java/javahl/native/JNIUtil.lo: subversion/bindings/java/javahl/native/JNIUtil.cpp subversion/bindings/java/javahl/native/JNICriticalSection.h subversion/bindings/java/javahl/native/JNIMutex.h subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIThreadData.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/SVNBase.h subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/JNIUtil.cpp

subversion/bindings/java/javahl/native/MessageReceiver.lo: subversion/bindings/java/javahl/native/MessageReceiver.cpp subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/MessageReceiver.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/MessageReceiver.cpp

subversion/bindings/java/javahl/native/Notify.lo: subversion/bindings/java/javahl/native/Notify.cpp subversion/bindings/java/javahl/native/EnumMapper.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Notify.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Notify.cpp

subversion/bindings/java/javahl/native/Notify2.lo: subversion/bindings/java/javahl/native/Notify2.cpp subversion/bindings/java/javahl/native/EnumMapper.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Notify2.h subversion/bindings/java/javahl/native/Path.h subversion/bindings/java/javahl/native/SVNBase.h subversion/bindings/java/javahl/native/SVNClient.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Notify2.cpp

subversion/bindings/java/javahl/native/Outputer.lo: subversion/bindings/java/javahl/native/Outputer.cpp subversion/bindings/java/javahl/native/JNIByteArray.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Outputer.h subversion/bindings/java/javahl/native/Pool.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Outputer.cpp

subversion/bindings/java/javahl/native/Path.lo: subversion/bindings/java/javahl/native/Path.cpp subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Path.h subversion/bindings/java/javahl/native/Pool.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Path.cpp

subversion/bindings/java/javahl/native/Pool.lo: subversion/bindings/java/javahl/native/Pool.cpp subversion/bindings/java/javahl/native/JNICriticalSection.h subversion/bindings/java/javahl/native/JNIMutex.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Pool.h subversion/include/svn_pools.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Pool.cpp

subversion/bindings/java/javahl/native/Prompter.lo: subversion/bindings/java/javahl/native/Prompter.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_PromptUserPassword2.h subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Pool.h subversion/bindings/java/javahl/native/Prompter.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Prompter.cpp

subversion/bindings/java/javahl/native/Revision.lo: subversion/bindings/java/javahl/native/Revision.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_RevisionKind.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Revision.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Revision.cpp

subversion/bindings/java/javahl/native/SVNAdmin.lo: subversion/bindings/java/javahl/native/SVNAdmin.cpp subversion/bindings/java/javahl/native/Inputer.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/MessageReceiver.h subversion/bindings/java/javahl/native/Outputer.h subversion/bindings/java/javahl/native/Path.h subversion/bindings/java/javahl/native/Pool.h subversion/bindings/java/javahl/native/Revision.h subversion/bindings/java/javahl/native/SVNAdmin.h subversion/bindings/java/javahl/native/SVNBase.h subversion/bindings/java/javahl/native/SVNClient.h subversion/bindings/java/javahl/native/Targets.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/SVNAdmin.cpp

subversion/bindings/java/javahl/native/SVNBase.lo: subversion/bindings/java/javahl/native/SVNBase.cpp subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/SVNBase.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/SVNBase.cpp

subversion/bindings/java/javahl/native/SVNClient.lo: subversion/bindings/java/javahl/native/SVNClient.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_NodeKind.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Revision.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_StatusKind.h subversion/bindings/java/javahl/native/BlameCallback.h subversion/bindings/java/javahl/native/CommitMessage.h subversion/bindings/java/javahl/native/EnumMapper.h subversion/bindings/java/javahl/native/JNIByteArray.h subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Notify.h subversion/bindings/java/javahl/native/Notify2.h subversion/bindings/java/javahl/native/Path.h subversion/bindings/java/javahl/native/Pool.h subversion/bindings/java/javahl/native/Prompter.h subversion/bindings/java/javahl/native/Revision.h subversion/bindings/java/javahl/native/SVNBase.h subversion/bindings/java/javahl/native/SVNClient.h subversion/bindings/java/javahl/native/Targets.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/SVNClient.cpp

subversion/bindings/java/javahl/native/Targets.lo: subversion/bindings/java/javahl/native/Targets.cpp subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Path.h subversion/bindings/java/javahl/native/Pool.h subversion/bindings/java/javahl/native/Targets.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/Targets.cpp

subversion/bindings/java/javahl/native/libsvnjavahl.la.lo: subversion/bindings/java/javahl/native/libsvnjavahl.la.c
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/libsvnjavahl.la.c

subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_Path.lo: subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_Path.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Path.h subversion/bindings/java/javahl/native/JNIStackElement.h subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Path.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_Path.cpp

subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_SVNAdmin.lo: subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_SVNAdmin.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNAdmin.h subversion/bindings/java/javahl/native/Inputer.h subversion/bindings/java/javahl/native/JNIByteArray.h subversion/bindings/java/javahl/native/JNIStackElement.h subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/MessageReceiver.h subversion/bindings/java/javahl/native/Outputer.h subversion/bindings/java/javahl/native/Path.h subversion/bindings/java/javahl/native/Pool.h subversion/bindings/java/javahl/native/Revision.h subversion/bindings/java/javahl/native/SVNAdmin.h subversion/bindings/java/javahl/native/SVNBase.h subversion/bindings/java/javahl/native/Targets.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_SVNAdmin.cpp

subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_SVNClient.lo: subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_SVNClient.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNClient.h subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_SVNClientLogLevel.h subversion/bindings/java/javahl/native/BlameCallback.h subversion/bindings/java/javahl/native/CommitMessage.h subversion/bindings/java/javahl/native/JNIByteArray.h subversion/bindings/java/javahl/native/JNIStackElement.h subversion/bindings/java/javahl/native/JNIStringHolder.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/bindings/java/javahl/native/Notify.h subversion/bindings/java/javahl/native/Notify2.h subversion/bindings/java/javahl/native/Outputer.h subversion/bindings/java/javahl/native/Path.h subversion/bindings/java/javahl/native/Pool.h subversion/bindings/java/javahl/native/Prompter.h subversion/bindings/java/javahl/native/Revision.h subversion/bindings/java/javahl/native/SVNBase.h subversion/bindings/java/javahl/native/SVNClient.h subversion/bindings/java/javahl/native/Targets.h subversion/bindings/java/javahl/native/version.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_SVNClient.cpp

subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_Version.lo: subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_Version.cpp subversion/bindings/java/javahl/include/org_tigris_subversion_javahl_Version.h subversion/bindings/java/javahl/native/JNIStackElement.h subversion/bindings/java/javahl/native/JNIUtil.h subversion/include/svn_types.h subversion/include/svn_version.h
	$(COMPILE_JAVAHL_CXX) $(abs_srcdir)/subversion/bindings/java/javahl/native/org_tigris_subversion_javahl_Version.cpp

subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.lo: subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/proxy/swig_perl_external_runtime.swg subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_SWIG_PL) $(abs_srcdir)/subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.c

subversion/bindings/swig/perl/native/core.lo: $(top_srcdir)/subversion/bindings/swig/perl/native/core.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) $(top_srcdir)/subversion/bindings/swig/perl/native/core.c

subversion/bindings/swig/perl/native/svn_client.lo: $(top_srcdir)/subversion/bindings/swig/perl/native/svn_client.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) $(top_srcdir)/subversion/bindings/swig/perl/native/svn_client.c

subversion/bindings/swig/perl/native/svn_delta.lo: $(top_srcdir)/subversion/bindings/swig/perl/native/svn_delta.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) $(top_srcdir)/subversion/bindings/swig/perl/native/svn_delta.c

subversion/bindings/swig/perl/native/svn_fs.lo: $(top_srcdir)/subversion/bindings/swig/perl/native/svn_fs.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) $(top_srcdir)/subversion/bindings/swig/perl/native/svn_fs.c

subversion/bindings/swig/perl/native/svn_ra.lo: $(top_srcdir)/subversion/bindings/swig/perl/native/svn_ra.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) $(top_srcdir)/subversion/bindings/swig/perl/native/svn_ra.c

subversion/bindings/swig/perl/native/svn_repos.lo: $(top_srcdir)/subversion/bindings/swig/perl/native/svn_repos.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) $(top_srcdir)/subversion/bindings/swig/perl/native/svn_repos.c

subversion/bindings/swig/perl/native/svn_wc.lo: $(top_srcdir)/subversion/bindings/swig/perl/native/svn_wc.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) $(top_srcdir)/subversion/bindings/swig/perl/native/svn_wc.c

subversion/bindings/swig/python/core.lo: $(top_srcdir)/subversion/bindings/swig/python/core.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) $(top_srcdir)/subversion/bindings/swig/python/core.c

subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.lo: subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.c subversion/bindings/swig/proxy/swig_python_external_runtime.swg subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_SWIG_PY) $(abs_srcdir)/subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.c

subversion/bindings/swig/python/svn_client.lo: $(top_srcdir)/subversion/bindings/swig/python/svn_client.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) $(top_srcdir)/subversion/bindings/swig/python/svn_client.c

subversion/bindings/swig/python/svn_delta.lo: $(top_srcdir)/subversion/bindings/swig/python/svn_delta.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) $(top_srcdir)/subversion/bindings/swig/python/svn_delta.c

subversion/bindings/swig/python/svn_fs.lo: $(top_srcdir)/subversion/bindings/swig/python/svn_fs.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) $(top_srcdir)/subversion/bindings/swig/python/svn_fs.c

subversion/bindings/swig/python/svn_ra.lo: $(top_srcdir)/subversion/bindings/swig/python/svn_ra.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) $(top_srcdir)/subversion/bindings/swig/python/svn_ra.c

subversion/bindings/swig/python/svn_repos.lo: $(top_srcdir)/subversion/bindings/swig/python/svn_repos.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) $(top_srcdir)/subversion/bindings/swig/python/svn_repos.c

subversion/bindings/swig/python/svn_wc.lo: $(top_srcdir)/subversion/bindings/swig/python/svn_wc.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) $(top_srcdir)/subversion/bindings/swig/python/svn_wc.c

subversion/bindings/swig/ruby/core.lo: $(top_srcdir)/subversion/bindings/swig/ruby/core.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) $(top_srcdir)/subversion/bindings/swig/ruby/core.c

subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.lo: subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.c subversion/bindings/swig/proxy/rubyhead.swg subversion/bindings/swig/proxy/swig_ruby_external_runtime.swg subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_nls.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_SWIG_RB) $(abs_srcdir)/subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.c

subversion/bindings/swig/ruby/svn_client.lo: $(top_srcdir)/subversion/bindings/swig/ruby/svn_client.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) $(top_srcdir)/subversion/bindings/swig/ruby/svn_client.c

subversion/bindings/swig/ruby/svn_delta.lo: $(top_srcdir)/subversion/bindings/swig/ruby/svn_delta.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) $(top_srcdir)/subversion/bindings/swig/ruby/svn_delta.c

subversion/bindings/swig/ruby/svn_fs.lo: $(top_srcdir)/subversion/bindings/swig/ruby/svn_fs.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) $(top_srcdir)/subversion/bindings/swig/ruby/svn_fs.c

subversion/bindings/swig/ruby/svn_ra.lo: $(top_srcdir)/subversion/bindings/swig/ruby/svn_ra.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) $(top_srcdir)/subversion/bindings/swig/ruby/svn_ra.c

subversion/bindings/swig/ruby/svn_repos.lo: $(top_srcdir)/subversion/bindings/swig/ruby/svn_repos.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) $(top_srcdir)/subversion/bindings/swig/ruby/svn_repos.c

subversion/bindings/swig/ruby/svn_wc.lo: $(top_srcdir)/subversion/bindings/swig/ruby/svn_wc.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) $(top_srcdir)/subversion/bindings/swig/ruby/svn_wc.c

subversion/libsvn_client/add.lo: subversion/libsvn_client/add.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/blame.lo: subversion/libsvn_client/blame.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/cat.lo: subversion/libsvn_client/cat.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/checkout.lo: subversion/libsvn_client/checkout.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/cleanup.lo: subversion/libsvn_client/cleanup.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/commit.lo: subversion/libsvn_client/commit.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/commit_util.lo: subversion/libsvn_client/commit_util.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/compat_providers.lo: subversion/libsvn_client/compat_providers.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h

subversion/libsvn_client/copy.lo: subversion/libsvn_client/copy.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/ctx.lo: subversion/libsvn_client/ctx.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h

subversion/libsvn_client/delete.lo: subversion/libsvn_client/delete.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/diff.lo: subversion/libsvn_client/diff.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/export.lo: subversion/libsvn_client/export.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/externals.lo: subversion/libsvn_client/externals.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/info.lo: subversion/libsvn_client/info.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/list.lo: subversion/libsvn_client/list.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/locking_commands.lo: subversion/libsvn_client/locking_commands.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/log.lo: subversion/libsvn_client/log.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/prop_commands.lo: subversion/libsvn_client/prop_commands.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_ctype.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/ra.lo: subversion/libsvn_client/ra.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/relocate.lo: subversion/libsvn_client/relocate.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/repos_diff.lo: subversion/libsvn_client/repos_diff.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/repos_diff_summarize.lo: subversion/libsvn_client/repos_diff_summarize.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/resolved.lo: subversion/libsvn_client/resolved.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/revert.lo: subversion/libsvn_client/revert.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/revisions.lo: subversion/libsvn_client/revisions.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/status.lo: subversion/libsvn_client/status.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/switch.lo: subversion/libsvn_client/switch.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/update.lo: subversion/libsvn_client/update.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/url.lo: subversion/libsvn_client/url.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/util.lo: subversion/libsvn_client/util.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h

subversion/libsvn_client/version.lo: subversion/libsvn_client/version.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h

subversion/libsvn_delta/cancel.lo: subversion/libsvn_delta/cancel.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/compose_delta.lo: subversion/libsvn_delta/compose_delta.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h

subversion/libsvn_delta/debug_editor.lo: subversion/libsvn_delta/debug_editor.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/debug_editor.h

subversion/libsvn_delta/default_editor.lo: subversion/libsvn_delta/default_editor.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/path_driver.lo: subversion/libsvn_delta/path_driver.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/svndiff.lo: subversion/libsvn_delta/svndiff.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h subversion/svn_private_config.h

subversion/libsvn_delta/text_delta.lo: subversion/libsvn_delta/text_delta.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h

subversion/libsvn_delta/vdelta.lo: subversion/libsvn_delta/vdelta.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h

subversion/libsvn_delta/version.lo: subversion/libsvn_delta/version.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/xdelta.lo: subversion/libsvn_delta/xdelta.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h

subversion/libsvn_diff/diff.lo: subversion/libsvn_diff/diff.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/diff3.lo: subversion/libsvn_diff/diff3.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/diff4.lo: subversion/libsvn_diff/diff4.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/diff_file.lo: subversion/libsvn_diff/diff_file.c subversion/include/svn_ctype.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h subversion/svn_private_config.h

subversion/libsvn_diff/lcs.lo: subversion/libsvn_diff/lcs.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/token.lo: subversion/libsvn_diff/token.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/util.lo: subversion/libsvn_diff/util.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_fs/access.lo: subversion/libsvn_fs/access.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h

subversion/libsvn_fs/fs-loader.lo: subversion/libsvn_fs/fs-loader.c subversion/include/svn_delta.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_fs/fs-loader.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/bdb-err.lo: subversion/libsvn_fs_base/bdb/bdb-err.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/bdb_compat.lo: subversion/libsvn_fs_base/bdb/bdb_compat.c subversion/libsvn_fs_base/bdb/bdb_compat.h

subversion/libsvn_fs_base/bdb/changes-table.lo: subversion/libsvn_fs_base/bdb/changes-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/copies-table.lo: subversion/libsvn_fs_base/bdb/copies-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/dbt.lo: subversion/libsvn_fs_base/bdb/dbt.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/util/skel.h

subversion/libsvn_fs_base/bdb/env.lo: subversion/libsvn_fs_base/bdb/env.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h

subversion/libsvn_fs_base/bdb/lock-tokens-table.lo: subversion/libsvn_fs_base/bdb/lock-tokens-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/lock-tokens-table.h subversion/libsvn_fs_base/bdb/locks-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h

subversion/libsvn_fs_base/bdb/locks-table.lo: subversion/libsvn_fs_base/bdb/locks-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/lock-tokens-table.h subversion/libsvn_fs_base/bdb/locks-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h

subversion/libsvn_fs_base/bdb/nodes-table.lo: subversion/libsvn_fs_base/bdb/nodes-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/reps-table.lo: subversion/libsvn_fs_base/bdb/reps-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/rev-table.lo: subversion/libsvn_fs_base/bdb/rev-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/strings-table.lo: subversion/libsvn_fs_base/bdb/strings-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/txn-table.lo: subversion/libsvn_fs_base/bdb/txn-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/uuids-table.lo: subversion/libsvn_fs_base/bdb/uuids-table.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/uuids-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/dag.lo: subversion/libsvn_fs_base/dag.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/dag.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/node-rev.h subversion/libsvn_fs_base/reps-strings.h subversion/libsvn_fs_base/revs-txns.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/svn_private_config.h

subversion/libsvn_fs_base/err.lo: subversion/libsvn_fs_base/err.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/id.h subversion/svn_private_config.h

subversion/libsvn_fs_base/fs.lo: subversion/libsvn_fs_base/fs.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/lock-tokens-table.h subversion/libsvn_fs_base/bdb/locks-table.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/bdb/uuids-table.h subversion/libsvn_fs_base/dag.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/lock.h subversion/libsvn_fs_base/revs-txns.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/tree.h subversion/libsvn_fs_base/uuid.h subversion/svn_private_config.h

subversion/libsvn_fs_base/id.lo: subversion/libsvn_fs_base/id.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/id.h

subversion/libsvn_fs_base/key-gen.lo: subversion/libsvn_fs_base/key-gen.c subversion/include/svn_types.h subversion/libsvn_fs_base/key-gen.h

subversion/libsvn_fs_base/lock.lo: subversion/libsvn_fs_base/lock.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/lock-tokens-table.h subversion/libsvn_fs_base/bdb/locks-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/lock.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_base/node-rev.lo: subversion/libsvn_fs_base/node-rev.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/node-rev.h subversion/libsvn_fs_base/reps-strings.h subversion/libsvn_fs_base/trail.h

subversion/libsvn_fs_base/reps-strings.lo: subversion/libsvn_fs_base/reps-strings.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/reps-strings.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/revs-txns.lo: subversion/libsvn_fs_base/revs-txns.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/dag.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/revs-txns.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_base/trail.lo: subversion/libsvn_fs_base/trail.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h

subversion/libsvn_fs_base/tree.lo: subversion/libsvn_fs_base/tree.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/dag.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/lock.h subversion/libsvn_fs_base/node-rev.h subversion/libsvn_fs_base/revs-txns.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_base/util/fs_skels.lo: subversion/libsvn_fs_base/util/fs_skels.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h

subversion/libsvn_fs_base/util/skel.lo: subversion/libsvn_fs_base/util/skel.c subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/util/skel.h

subversion/libsvn_fs_base/uuid.lo: subversion/libsvn_fs_base/uuid.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/uuids-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/uuid.h

subversion/libsvn_fs_fs/dag.lo: subversion/libsvn_fs_fs/dag.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/dag.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/id.h subversion/libsvn_fs_fs/key-gen.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/err.lo: subversion/libsvn_fs_fs/err.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/id.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/fs.lo: subversion/libsvn_fs_fs/fs.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/dag.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/lock.h subversion/libsvn_fs_fs/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/fs_fs.lo: subversion/libsvn_fs_fs/fs_fs.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/id.h subversion/libsvn_fs_fs/key-gen.h subversion/libsvn_fs_fs/lock.h subversion/libsvn_fs_fs/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/id.lo: subversion/libsvn_fs_fs/id.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/id.h

subversion/libsvn_fs_fs/key-gen.lo: subversion/libsvn_fs_fs/key-gen.c subversion/include/svn_types.h subversion/libsvn_fs_fs/key-gen.h

subversion/libsvn_fs_fs/lock.lo: subversion/libsvn_fs_fs/lock.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/lock.h subversion/libsvn_fs_fs/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/tree.lo: subversion/libsvn_fs_fs/tree.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/dag.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/id.h subversion/libsvn_fs_fs/key-gen.h subversion/libsvn_fs_fs/lock.h subversion/libsvn_fs_fs/tree.h subversion/svn_private_config.h

subversion/libsvn_ra/ra_loader.lo: subversion/libsvn_ra/ra_loader.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/commit.lo: subversion/libsvn_ra_dav/commit.c subversion/include/svn_auth.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/fetch.lo: subversion/libsvn_ra_dav/fetch.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/file_revs.lo: subversion/libsvn_ra_dav/file_revs.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/log.lo: subversion/libsvn_ra_dav/log.c subversion/include/svn_auth.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/merge.lo: subversion/libsvn_ra_dav/merge.c subversion/include/svn_auth.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/options.lo: subversion/libsvn_ra_dav/options.c subversion/include/svn_auth.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/props.lo: subversion/libsvn_ra_dav/props.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/replay.lo: subversion/libsvn_ra_dav/replay.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/session.lo: subversion/libsvn_ra_dav/session.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra/wrapper_template.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_dav/util.lo: subversion/libsvn_ra_dav/util.c subversion/include/svn_auth.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra_dav/ra_dav.h subversion/svn_private_config.h

subversion/libsvn_ra_local/ra_plugin.lo: subversion/libsvn_ra_local/ra_plugin.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra/wrapper_template.h subversion/libsvn_ra_local/ra_local.h subversion/svn_private_config.h

subversion/libsvn_ra_local/split_url.lo: subversion/libsvn_ra_local/split_url.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_local/ra_local.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/blame.lo: subversion/libsvn_ra_serf/blame.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/commit.lo: subversion/libsvn_ra_serf/commit.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/getdate.lo: subversion/libsvn_ra_serf/getdate.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/getlocations.lo: subversion/libsvn_ra_serf/getlocations.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/getlocks.lo: subversion/libsvn_ra_serf/getlocks.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/locks.lo: subversion/libsvn_ra_serf/locks.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/log.lo: subversion/libsvn_ra_serf/log.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/merge.lo: subversion/libsvn_ra_serf/merge.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/options.lo: subversion/libsvn_ra_serf/options.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/property.lo: subversion/libsvn_ra_serf/property.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_serf/ra_serf.h

subversion/libsvn_ra_serf/propfind_buckets.lo: subversion/libsvn_ra_serf/propfind_buckets.c subversion/include/svn_auth.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_serf/ra_serf.h

subversion/libsvn_ra_serf/replay.lo: subversion/libsvn_ra_serf/replay.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/serf.lo: subversion/libsvn_ra_serf/serf.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra/wrapper_template.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/update.lo: subversion/libsvn_ra_serf/update.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/util.lo: subversion/libsvn_ra_serf/util.c subversion/include/svn_auth.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/xml.lo: subversion/libsvn_ra_serf/xml.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/client.lo: subversion/libsvn_ra_svn/client.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra/wrapper_template.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/cram.lo: subversion/libsvn_ra_svn/cram.c subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/editor.lo: subversion/libsvn_ra_svn/editor.c subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/editorp.lo: subversion/libsvn_ra_svn/editorp.c subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/marshal.lo: subversion/libsvn_ra_svn/marshal.c subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/version.lo: subversion/libsvn_ra_svn/version.c subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_props.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_repos/authz.lo: subversion/libsvn_repos/authz.c subversion/include/svn_config.h subversion/include/svn_ctype.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_repos/commit.lo: subversion/libsvn_repos/commit.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_repos/delta.lo: subversion/libsvn_repos/delta.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/dump.lo: subversion/libsvn_repos/dump.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_repos/fs-wrap.lo: subversion/libsvn_repos/fs-wrap.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/hooks.lo: subversion/libsvn_repos/hooks.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/load.lo: subversion/libsvn_repos/load.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/log.lo: subversion/libsvn_repos/log.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/node_tree.lo: subversion/libsvn_repos/node_tree.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/replay.lo: subversion/libsvn_repos/replay.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_repos/reporter.lo: subversion/libsvn_repos/reporter.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/repos.lo: subversion/libsvn_repos/repos.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/rev_hunt.lo: subversion/libsvn_repos/rev_hunt.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_subr/auth.lo: subversion/libsvn_subr/auth.c subversion/include/svn_auth.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/cmdline.lo: subversion/libsvn_subr/cmdline.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_nls.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/libsvn_subr/utf_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/compat.lo: subversion/libsvn_subr/compat.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/config.lo: subversion/libsvn_subr/config.c subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_subr/config_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/config_auth.lo: subversion/libsvn_subr/config_auth.c subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_subr/config_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/config_file.lo: subversion/libsvn_subr/config_file.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/libsvn_subr/config_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/config_win.lo: subversion/libsvn_subr/config_win.c subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/libsvn_subr/config_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/constructors.lo: subversion/libsvn_subr/constructors.c subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/ctype.lo: subversion/libsvn_subr/ctype.c subversion/include/svn_ctype.h

subversion/libsvn_subr/date.lo: subversion/libsvn_subr/date.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/dso.lo: subversion/libsvn_subr/dso.c subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/error.lo: subversion/libsvn_subr/error.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/hash.lo: subversion/libsvn_subr/hash.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/io.lo: subversion/libsvn_subr/io.c subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/kitchensink.lo: subversion/libsvn_subr/kitchensink.c subversion/include/svn_types.h

subversion/libsvn_subr/lock.lo: subversion/libsvn_subr/lock.c subversion/include/svn_types.h

subversion/libsvn_subr/md5.lo: subversion/libsvn_subr/md5.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_md5.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/nls.lo: subversion/libsvn_subr/nls.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_nls.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/opt.lo: subversion/libsvn_subr/opt.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/path.lo: subversion/libsvn_subr/path.c subversion/include/svn_ctype.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/pool.lo: subversion/libsvn_subr/pool.c subversion/include/svn_pools.h subversion/include/svn_types.h

subversion/libsvn_subr/prompt.lo: subversion/libsvn_subr/prompt.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/quoprint.lo: subversion/libsvn_subr/quoprint.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_quoprint.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/simple_providers.lo: subversion/libsvn_subr/simple_providers.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/sorts.lo: subversion/libsvn_subr/sorts.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/ssl_client_cert_providers.lo: subversion/libsvn_subr/ssl_client_cert_providers.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/ssl_client_cert_pw_providers.lo: subversion/libsvn_subr/ssl_client_cert_pw_providers.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/ssl_server_trust_providers.lo: subversion/libsvn_subr/ssl_server_trust_providers.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/stream.lo: subversion/libsvn_subr/stream.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/subst.lo: subversion/libsvn_subr/subst.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/svn_base64.lo: subversion/libsvn_subr/svn_base64.c subversion/include/svn_base64.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/svn_string.lo: subversion/libsvn_subr/svn_string.c subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/target.lo: subversion/libsvn_subr/target.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/time.lo: subversion/libsvn_subr/time.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/user.lo: subversion/libsvn_subr/user.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h

subversion/libsvn_subr/username_providers.lo: subversion/libsvn_subr/username_providers.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h

subversion/libsvn_subr/utf.lo: subversion/libsvn_subr/utf.c subversion/include/svn_ctype.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/libsvn_subr/utf_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/utf_validate.lo: subversion/libsvn_subr/utf_validate.c subversion/include/svn_types.h subversion/libsvn_subr/utf_impl.h

subversion/libsvn_subr/validate.lo: subversion/libsvn_subr/validate.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/version.lo: subversion/libsvn_subr/version.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/xml.lo: subversion/libsvn_subr/xml.c subversion/include/svn_ctype.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_xml.h subversion/libsvn_subr/utf_impl.h subversion/svn_private_config.h

subversion/libsvn_wc/adm_crawler.lo: subversion/libsvn_wc/adm_crawler.c subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/adm_files.lo: subversion/libsvn_wc/adm_files.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/adm_ops.lo: subversion/libsvn_wc/adm_ops.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/adm_ops.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/copy.lo: subversion/libsvn_wc/copy.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/diff.lo: subversion/libsvn_wc/diff.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/props.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/entries.lo: subversion/libsvn_wc/entries.c subversion/include/svn_auth.h subversion/include/svn_ctype.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/adm_ops.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/lock.lo: subversion/libsvn_wc/lock.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/log.lo: subversion/libsvn_wc/log.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/merge.lo: subversion/libsvn_wc/merge.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/log.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/props.lo: subversion/libsvn_wc/props.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/questions.lo: subversion/libsvn_wc/questions.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/relocate.lo: subversion/libsvn_wc/relocate.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/props.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/revision_status.lo: subversion/libsvn_wc/revision_status.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h

subversion/libsvn_wc/status.lo: subversion/libsvn_wc/status.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/translate.lo: subversion/libsvn_wc/translate.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/update_editor.lo: subversion/libsvn_wc/update_editor.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/adm_ops.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/util.lo: subversion/libsvn_wc/util.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/mod_authz_svn/mod_authz_svn.lo: subversion/mod_authz_svn/mod_authz_svn.c subversion/include/mod_dav_svn.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_authz_svn/mod_authz_svn.c

subversion/mod_dav_svn/activity.lo: subversion/mod_dav_svn/activity.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/activity.c

subversion/mod_dav_svn/deadprops.lo: subversion/mod_dav_svn/deadprops.c subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/deadprops.c

subversion/mod_dav_svn/file_revs.lo: subversion/mod_dav_svn/file_revs.c subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/file_revs.c

subversion/mod_dav_svn/liveprops.lo: subversion/mod_dav_svn/liveprops.c subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/liveprops.c

subversion/mod_dav_svn/lock.lo: subversion/mod_dav_svn/lock.c subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/lock.c

subversion/mod_dav_svn/log.lo: subversion/mod_dav_svn/log.c subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/log.c

subversion/mod_dav_svn/merge.lo: subversion/mod_dav_svn/merge.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/merge.c

subversion/mod_dav_svn/mod_dav_svn.lo: subversion/mod_dav_svn/mod_dav_svn.c subversion/include/mod_dav_svn.h subversion/include/svn_delta.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/mod_dav_svn.c

subversion/mod_dav_svn/replay.lo: subversion/mod_dav_svn/replay.c subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/replay.c

subversion/mod_dav_svn/repos.lo: subversion/mod_dav_svn/repos.c subversion/include/mod_dav_svn.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/repos.c

subversion/mod_dav_svn/update.lo: subversion/mod_dav_svn/update.c subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/update.c

subversion/mod_dav_svn/util.lo: subversion/mod_dav_svn/util.c subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/util.c

subversion/mod_dav_svn/version.lo: subversion/mod_dav_svn/version.c subversion/include/svn_base64.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(abs_srcdir)/subversion/mod_dav_svn/version.c

subversion/po/de.mo: subversion/po/de.po

subversion/po/es.mo: subversion/po/es.po

subversion/po/fr.mo: subversion/po/fr.po

subversion/po/it.mo: subversion/po/it.po

subversion/po/ja.mo: subversion/po/ja.po

subversion/po/ko.mo: subversion/po/ko.po

subversion/po/nb.mo: subversion/po/nb.po

subversion/po/pl.mo: subversion/po/pl.po

subversion/po/pt_BR.mo: subversion/po/pt_BR.po

subversion/po/sv.mo: subversion/po/sv.po

subversion/po/zh_CN.mo: subversion/po/zh_CN.po

subversion/po/zh_TW.mo: subversion/po/zh_TW.po

subversion/svn/add-cmd.o: subversion/svn/add-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/blame-cmd.o: subversion/svn/blame-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/cat-cmd.o: subversion/svn/cat-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/checkout-cmd.o: subversion/svn/checkout-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/cleanup-cmd.o: subversion/svn/cleanup-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/commit-cmd.o: subversion/svn/commit-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/copy-cmd.o: subversion/svn/copy-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/delete-cmd.o: subversion/svn/delete-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/diff-cmd.o: subversion/svn/diff-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/export-cmd.o: subversion/svn/export-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/help-cmd.o: subversion/svn/help-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/import-cmd.o: subversion/svn/import-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/info-cmd.o: subversion/svn/info-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/list-cmd.o: subversion/svn/list-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/lock-cmd.o: subversion/svn/lock-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/log-cmd.o: subversion/svn/log-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/main.o: subversion/svn/main.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/merge-cmd.o: subversion/svn/merge-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/mkdir-cmd.o: subversion/svn/mkdir-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/move-cmd.o: subversion/svn/move-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/notify.o: subversion/svn/notify.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/propdel-cmd.o: subversion/svn/propdel-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/propedit-cmd.o: subversion/svn/propedit-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/propget-cmd.o: subversion/svn/propget-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/proplist-cmd.o: subversion/svn/proplist-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/props.o: subversion/svn/props.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/propset-cmd.o: subversion/svn/propset-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/resolved-cmd.o: subversion/svn/resolved-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/revert-cmd.o: subversion/svn/revert-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/status-cmd.o: subversion/svn/status-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/status.o: subversion/svn/status.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/switch-cmd.o: subversion/svn/switch-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/unlock-cmd.o: subversion/svn/unlock-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/update-cmd.o: subversion/svn/update-cmd.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/util.o: subversion/svn/util.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svnadmin/main.o: subversion/svnadmin/main.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/svndumpfilter/main.o: subversion/svndumpfilter/main.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/svnlook/main.o: subversion/svnlook/main.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/svnserve/main.o: subversion/svnserve/main.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra_svn.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/svnserve/server.h subversion/svnserve/winservice.h

subversion/svnserve/serve.o: subversion/svnserve/serve.c subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra_svn.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/svnserve/server.h

subversion/svnserve/winservice.o: subversion/svnserve/winservice.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h subversion/svnserve/winservice.h

subversion/svnsync/main.o: subversion/svnsync/main.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/svnversion/main.o: subversion/svnversion/main.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h

subversion/tests/libsvn_delta/random-test.o: subversion/tests/libsvn_delta/random-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/compose_delta.c subversion/libsvn_delta/delta.h subversion/tests/libsvn_delta/delta-window-test.h subversion/tests/libsvn_delta/range-index-test.h subversion/tests/svn_test.h

subversion/tests/libsvn_delta/svndiff-test.o: subversion/tests/libsvn_delta/svndiff-test.c subversion/include/svn_base64.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_quoprint.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/tests/libsvn_delta/vdelta-test.o: subversion/tests/libsvn_delta/vdelta-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h subversion/tests/libsvn_delta/delta-window-test.h

subversion/tests/libsvn_diff/diff-diff3-test.o: subversion/tests/libsvn_diff/diff-diff3-test.c subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_fs/fs-test.o: subversion/tests/libsvn_fs/fs-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs/locks-test.o: subversion/tests/libsvn_fs/locks-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs_base/changes-test.o: subversion/tests/libsvn_fs_base/changes-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs_base/fs-base-test.o: subversion/tests/libsvn_fs_base/fs-base-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_md5.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/trail.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs_base/key-test.o: subversion/tests/libsvn_fs_base/key-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/key-gen.h subversion/tests/svn_test.h

subversion/tests/libsvn_fs_base/skel-test.o: subversion/tests/libsvn_fs_base/skel-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/util/skel.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs_base/strings-reps-test.o: subversion/tests/libsvn_fs_base/strings-reps-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/libsvn_fs_base/util/skel.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_ra_local/ra-local-test.o: subversion/tests/libsvn_ra_local/ra-local-test.c subversion/include/svn_auth.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_ra_local/ra_local.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_repos/dir-delta-editor.o: subversion/tests/libsvn_repos/dir-delta-editor.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/libsvn_repos/dir-delta-editor.h subversion/tests/svn_test.h

subversion/tests/libsvn_repos/repos-test.o: subversion/tests/libsvn_repos/repos-test.c subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/libsvn_repos/dir-delta-editor.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_subr/compat-test.o: subversion/tests/libsvn_subr/compat-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/config-test.o: subversion/tests/libsvn_subr/config-test.c subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/hashdump-test.o: subversion/tests/libsvn_subr/hashdump-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/opt-test.o: subversion/tests/libsvn_subr/opt-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/path-test.o: subversion/tests/libsvn_subr/path-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/stream-test.o: subversion/tests/libsvn_subr/stream-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/string-test.o: subversion/tests/libsvn_subr/string-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/target-test.o: subversion/tests/libsvn_subr/target-test.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h

subversion/tests/libsvn_subr/time-test.o: subversion/tests/libsvn_subr/time-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/utf-test.o: subversion/tests/libsvn_subr/utf-test.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_subr/utf_impl.h subversion/tests/svn_test.h

subversion/tests/libsvn_wc/translate-test.o: subversion/tests/libsvn_wc/translate-test.c subversion/include/svn_auth.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/tests/svn_test.h

subversion/tests/svn_test_editor.lo: subversion/tests/svn_test_editor.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/svn_test_fs.lo: subversion/tests/svn_test_fs.c subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/svn_test_main.lo: subversion/tests/svn_test_main.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/tests/svn_test.h

tools/diff/diff.o: tools/diff/diff.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

tools/diff/diff3.o: tools/diff/diff3.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

tools/diff/diff4.o: tools/diff/diff4.c subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

tools/server-side/svnauthz-validate.o: tools/server-side/svnauthz-validate.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h

