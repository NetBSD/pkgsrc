# Copyright (c) 2017 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

doc_DATA = AUTHORS COPYING README.md
noinst_DATA = README.md
EXTRA_DIST = $(doc_DATA)

PHONY_TARGETS = 

CHMOD = chmod
MV = mv

# Assume that $source and $target are in the same directory.
BUILD_FILE = \
	$(SED)	-e "s,__POSIX_SHELL__,$(POSIX_SHELL),g" \
		-e "s,__TASK_MODULE_DIR__,$(pkgdatadir),g" \
		-e "s,__TASK_TESTS_DIR__,$(pkgtestsdir),g" \
		-e "s,__TASK_VERSION__,$(PACKAGE_VERSION),g" \
		< "$$source" > "$$target.tmp" && \
	$(MV) -f "$$target.tmp" "$$target"

BUILD_SCRIPT = $(BUILD_FILE) && $(CHMOD) +x "$$target"

dist_pkgdata_DATA = cleanup.subr
dist_pkgdata_DATA += compare.subr
dist_pkgdata_DATA += createfile.subr
dist_pkgdata_DATA += directories.subr
dist_pkgdata_DATA += dirwalk.subr
dist_pkgdata_DATA += echo.subr
dist_pkgdata_DATA += files.subr
dist_pkgdata_DATA += fonts.subr
dist_pkgdata_DATA += groups.subr
dist_pkgdata_DATA += info_files.subr
dist_pkgdata_DATA += load.subr
dist_pkgdata_DATA += lock.subr
dist_pkgdata_DATA += makedir.subr
dist_pkgdata_DATA += maketemp.subr
dist_pkgdata_DATA += match.subr
dist_pkgdata_DATA += ocaml_findlib.subr
dist_pkgdata_DATA += permissions.subr
dist_pkgdata_DATA += platform.subr
dist_pkgdata_DATA += postinstall.subr
dist_pkgdata_DATA += postremove.subr
dist_pkgdata_DATA += preinstall.subr
dist_pkgdata_DATA += preremove.subr
dist_pkgdata_DATA += quote.subr
dist_pkgdata_DATA += random.subr
dist_pkgdata_DATA += refcount.subr
dist_pkgdata_DATA += refcount_file.subr
dist_pkgdata_DATA += say.subr
dist_pkgdata_DATA += shells.subr
dist_pkgdata_DATA += shlibs.subr
dist_pkgdata_DATA += sort.subr
dist_pkgdata_DATA += taskfunc.subr
dist_pkgdata_DATA += tee.subr
dist_pkgdata_DATA += truthy.subr
dist_pkgdata_DATA += unittest.subr
dist_pkgdata_DATA += usergroup.subr
dist_pkgdata_DATA += usergroup_FreeBSD.subr
dist_pkgdata_DATA += usergroup_Linux.subr
dist_pkgdata_DATA += usergroup_MirBSD.subr
dist_pkgdata_DATA += usergroup_NetBSD.subr
dist_pkgdata_DATA += usergroup_exists.subr
dist_pkgdata_DATA += usergroup_mock.subr
dist_pkgdata_DATA += users.subr
dist_pkgdata_DATA += valid_options.subr
dist_pkgdata_DATA += which.subr

pkgdata_DATA = version.subr
CLEANFILES = version.subr
EXTRA_DIST += version.subr.in
version.subr: version.subr.in
	-$(MKDIR_P) $(builddir)
	$(AM_V_GEN)target="$(builddir)/version.subr" source="$(srcdir)/version.subr.in"; \
	$(BUILD_FILE)

# Build a test script.
BUILD_TEST = \
	TASK_MODULE_DIR="$(top_srcdir)" TASK_TESTS_DIR="$(top_srcdir)/t" \
	$(builddir)/t/build_test -o "$$target" "$$source"
dist_pkgtests_DATA = t/Kyuafile

noinst_SCRIPTS = t/build_test
CLEANFILES += t/build_test
EXTRA_DIST += t/build_test.sh
t/build_test: t/build_test.sh
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/build_test" source="$(srcdir)/t/build_test.sh"; \
	$(BUILD_SCRIPT)

pkgtests_SCRIPTS = t/run_tests
CLEANFILES += t/run_tests
EXTRA_DIST += t/run_tests.sh
t/run_tests: t/run_tests.sh
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/run_tests" source="$(srcdir)/t/run_tests.sh"; \
	$(BUILD_SCRIPT)

pkgtests_SCRIPTS += t/t_compare
CLEANFILES += t/t_compare
EXTRA_DIST += t/t_compare.sh
t/t_compare: t/t_compare.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_compare" source="$(srcdir)/t/t_compare.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_createfile
CLEANFILES += t/t_createfile
EXTRA_DIST += t/t_createfile.sh
t/t_createfile: t/t_createfile.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_createfile" source="$(srcdir)/t/t_createfile.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_directories
CLEANFILES += t/t_directories
EXTRA_DIST += t/t_directories.sh
t/t_directories: t/t_directories.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_directories" source="$(srcdir)/t/t_directories.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_dirwalk
CLEANFILES += t/t_dirwalk
EXTRA_DIST += t/t_dirwalk.sh
t/t_dirwalk: t/t_dirwalk.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_dirwalk" source="$(srcdir)/t/t_dirwalk.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_echo
CLEANFILES += t/t_echo
EXTRA_DIST += t/t_echo.sh
t/t_echo: t/t_echo.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_echo" source="$(srcdir)/t/t_echo.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_files
CLEANFILES += t/t_files
EXTRA_DIST += t/t_files.sh
t/t_files: t/t_files.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_files" source="$(srcdir)/t/t_files.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_fonts
CLEANFILES += t/t_fonts
EXTRA_DIST += t/t_fonts.sh
t/t_fonts: t/t_fonts.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_fonts" source="$(srcdir)/t/t_fonts.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_groups
CLEANFILES += t/t_groups
EXTRA_DIST += t/t_groups.sh
t/t_groups: t/t_groups.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_groups" source="$(srcdir)/t/t_groups.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_info_files
CLEANFILES += t/t_info_files
EXTRA_DIST += t/t_info_files.sh
t/t_info_files: t/t_info_files.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_info_files" source="$(srcdir)/t/t_info_files.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_lock
CLEANFILES += t/t_lock
EXTRA_DIST += t/t_lock.sh
t/t_lock: t/t_lock.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_lock" source="$(srcdir)/t/t_lock.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_makedir
CLEANFILES += t/t_makedir
EXTRA_DIST += t/t_makedir.sh
t/t_makedir: t/t_makedir.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_makedir" source="$(srcdir)/t/t_makedir.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_maketemp
CLEANFILES += t/t_maketemp
EXTRA_DIST += t/t_maketemp.sh
t/t_maketemp: t/t_maketemp.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_maketemp" source="$(srcdir)/t/t_maketemp.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_match
CLEANFILES += t/t_match
EXTRA_DIST += t/t_match.sh
t/t_match: t/t_match.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_match" source="$(srcdir)/t/t_match.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_ocaml_findlib
CLEANFILES += t/t_ocaml_findlib
EXTRA_DIST += t/t_ocaml_findlib.sh
t/t_ocaml_findlib: t/t_ocaml_findlib.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_ocaml_findlib" source="$(srcdir)/t/t_ocaml_findlib.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_permissions
CLEANFILES += t/t_permissions
EXTRA_DIST += t/t_permissions.sh
t/t_permissions: t/t_permissions.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_permissions" source="$(srcdir)/t/t_permissions.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_platform
CLEANFILES += t/t_platform
EXTRA_DIST += t/t_platform.sh
t/t_platform: t/t_platform.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_platform" source="$(srcdir)/t/t_platform.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_postinstall
CLEANFILES += t/t_postinstall
EXTRA_DIST += t/t_postinstall.sh
t/t_postinstall: t/t_postinstall.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_postinstall" source="$(srcdir)/t/t_postinstall.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_postremove
CLEANFILES += t/t_postremove
EXTRA_DIST += t/t_postremove.sh
t/t_postremove: t/t_postremove.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_postremove" source="$(srcdir)/t/t_postremove.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_preinstall
CLEANFILES += t/t_preinstall
EXTRA_DIST += t/t_preinstall.sh
t/t_preinstall: t/t_preinstall.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_preinstall" source="$(srcdir)/t/t_preinstall.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_preremove
CLEANFILES += t/t_preremove
EXTRA_DIST += t/t_preremove.sh
t/t_preremove: t/t_preremove.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_preremove" source="$(srcdir)/t/t_preremove.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_quote
CLEANFILES += t/t_quote
EXTRA_DIST += t/t_quote.sh
t/t_quote: t/t_quote.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_quote" source="$(srcdir)/t/t_quote.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_random
CLEANFILES += t/t_random
EXTRA_DIST += t/t_random.sh
t/t_random: t/t_random.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_random" source="$(srcdir)/t/t_random.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_refcount
CLEANFILES += t/t_refcount
EXTRA_DIST += t/t_refcount.sh
t/t_refcount: t/t_refcount.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_refcount" source="$(srcdir)/t/t_refcount.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_shells
CLEANFILES += t/t_shells
EXTRA_DIST += t/t_shells.sh
t/t_shells: t/t_shells.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_shells" source="$(srcdir)/t/t_shells.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_shlibs
CLEANFILES += t/t_shlibs
EXTRA_DIST += t/t_shlibs.sh
t/t_shlibs: t/t_shlibs.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_shlibs" source="$(srcdir)/t/t_shlibs.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_sort
CLEANFILES += t/t_sort
EXTRA_DIST += t/t_sort.sh
t/t_sort: t/t_sort.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_sort" source="$(srcdir)/t/t_sort.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_taskfunc
CLEANFILES += t/t_taskfunc
EXTRA_DIST += t/t_taskfunc.sh
t/t_taskfunc: t/t_taskfunc.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_taskfunc" source="$(srcdir)/t/t_taskfunc.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_tee
CLEANFILES += t/t_tee
EXTRA_DIST += t/t_tee.sh
t/t_tee: t/t_tee.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_tee" source="$(srcdir)/t/t_tee.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_truthy
CLEANFILES += t/t_truthy
EXTRA_DIST += t/t_truthy.sh
t/t_truthy: t/t_truthy.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_truthy" source="$(srcdir)/t/t_truthy.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_usergroup
CLEANFILES += t/t_usergroup
EXTRA_DIST += t/t_usergroup.sh
t/t_usergroup: t/t_usergroup.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_usergroup" source="$(srcdir)/t/t_usergroup.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_usergroup_FreeBSD
CLEANFILES += t/t_usergroup_FreeBSD
EXTRA_DIST += t/t_usergroup_FreeBSD.sh
t/t_usergroup_FreeBSD: t/t_usergroup_FreeBSD.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_usergroup_FreeBSD" source="$(srcdir)/t/t_usergroup_FreeBSD.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_usergroup_Linux
CLEANFILES += t/t_usergroup_Linux
EXTRA_DIST += t/t_usergroup_Linux.sh
t/t_usergroup_Linux: t/t_usergroup_Linux.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_usergroup_Linux" source="$(srcdir)/t/t_usergroup_Linux.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_usergroup_MirBSD
CLEANFILES += t/t_usergroup_MirBSD
EXTRA_DIST += t/t_usergroup_MirBSD.sh
t/t_usergroup_MirBSD: t/t_usergroup_MirBSD.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_usergroup_MirBSD" source="$(srcdir)/t/t_usergroup_MirBSD.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_usergroup_NetBSD
CLEANFILES += t/t_usergroup_NetBSD
EXTRA_DIST += t/t_usergroup_NetBSD.sh
t/t_usergroup_NetBSD: t/t_usergroup_NetBSD.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_usergroup_NetBSD" source="$(srcdir)/t/t_usergroup_NetBSD.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_usergroup_exists
CLEANFILES += t/t_usergroup_exists
EXTRA_DIST += t/t_usergroup_exists.sh
t/t_usergroup_exists: t/t_usergroup_exists.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_usergroup_exists" source="$(srcdir)/t/t_usergroup_exists.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_usergroup_mock
CLEANFILES += t/t_usergroup_mock
EXTRA_DIST += t/t_usergroup_mock.sh
t/t_usergroup_mock: t/t_usergroup_mock.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_usergroup_mock" source="$(srcdir)/t/t_usergroup_mock.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_users
CLEANFILES += t/t_users
EXTRA_DIST += t/t_users.sh
t/t_users: t/t_users.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_users" source="$(srcdir)/t/t_users.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_valid_options
CLEANFILES += t/t_valid_options
EXTRA_DIST += t/t_valid_options.sh
t/t_valid_options: t/t_valid_options.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_valid_options" source="$(srcdir)/t/t_valid_options.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_version
CLEANFILES += t/t_version
EXTRA_DIST += t/t_version.sh
t/t_version: t/t_version.sh version.subr $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_version" source="$(srcdir)/t/t_version.sh"; \
	$(BUILD_TEST)

pkgtests_SCRIPTS += t/t_which
CLEANFILES += t/t_which
EXTRA_DIST += t/t_which.sh
t/t_which: t/t_which.sh $(builddir)/t/build_test
	-$(MKDIR_P) $(builddir)/t
	$(AM_V_GEN)target="$(builddir)/t/t_which" source="$(srcdir)/t/t_which.sh"; \
	$(BUILD_TEST)

PHONY_TARGETS += check-run-tets
check-run-tests:
	@cd $(srcdir)/t && $(SHELL) run_tests.sh

PHONY_TARGETS += installcheck-run-tests
installcheck-run-tests:
	@cd $(pkgtestsdir) && ./run_tests

if HAVE_KYUA
# CHECK_ENVIRONMENT
#	This is used to set variables before calling kyua on the tests in
#	the build directory.
#
# TESTS_ENVIRONMENT
#	This is used to set variables before calling kyua, regardless of
#	whether the tests are installed or in the build directory.

CHECK_ENVIRONMENT = \
	TASK_MODULE_DIR=$(abs_top_srcdir) \
	TASK_TESTS_DIR=$(abs_top_srcdir)/t

PHONY_TARGETS += check-kyua
check-local: check-kyua
check-kyua:
	@failed=no; \
	$(CHECK_ENVIRONMENT) $(TESTS_ENVIRONMENT) $(KYUA) test \
		--kyuafile='$(top_srcdir)/t/Kyuafile' \
		--build-root='$(top_builddir)/t' || failed=yes; \
	if [ "$$failed" = yes ]; then \
		$(CHECK_ENVIRONMENT) $(TESTS_ENVIRONMENT) $(KYUA) report \
			--results-file='$(abs_top_srcdir)' \
			--verbose --results-filter=broken,failed; \
		exit 1; \
	fi

PHONY_TARGETS += installcheck-kyua
installcheck-local: installcheck-kyua
installcheck-kyua:
	@failed=no; \
	cd $(pkgtestsdir) && $(TESTS_ENVIRONMENT) $(KYUA) test  || failed=yes; \
	if [ "$$failed" = yes ]; then \
		cd $(pkgtestsdir) && $(TESTS_ENVIRONMENT) $(KYUA) report \
			--verbose --results-filter=broken,failed; \
		exit 1; \
	fi
else  # HAVE_KYUA
check-local: check-run-tests
installcheck-local: installcheck-run-tests
endif # HAVE_KYUA

maintainer-clean-local:
	-rm -f Makefile.in aclocal.m4 configure
	-rm -f build-aux/install-sh build-aux/missing
	-rm -f $(PACKAGE)-*.tar.*
