#############################################################

LIBEXECDIR ?=	${PREFIX}/libexec/psu
DOCDIR ?=	${DATADIR}/doc/pkg_summary-utils
EGDIR ?=	${DOCDIR}/examples
AWKMODDIR ?=	${DATADIR}/runawk
MKSCRIPTSDIR ?=	${DATADIR}/psu_mk
DISTDIR ?=	/usr/pkgsrc/distfiles

SH ?=		/bin/sh
AWK ?=		/usr/bin/awk
PKG_INFO_CMD ?=	/usr/sbin/pkg_info -K /var/db/pkg

# NetBSD make is required for pkgsrc
BMAKE ?=	/usr/bin/make

#############################################################

LIBEXECSCRIPTS =	direct_deps XB2bin_summary get_processed_pkgs

INSCRIPTS =	pkg_cmp_summary pkg_list_all_pkgs
INSCRIPTS +=	pkg_refresh_summary pkg_src_fetch_var
INSCRIPTS +=	pkg_micro_src_summary pkg_src_summary
INSCRIPTS +=	pkg_update_src_summary pkg_summary4view
INSCRIPTS +=	pkg_update_summary pkg_grep_summary
INSCRIPTS +=	cvs_checksum pkg_assignments2pkgpath
INSCRIPTS +=	pkg_uniq_summary pkg_summary2bb_pkgs
INSCRIPTS +=	pkg_cleanup_distdir pkg_summary2build_graph
INSCRIPTS +=	pkg_summary2deps pkg_lint_summary
INSCRIPTS +=	pkg_subgraph_deps pkg_bin_summary
INSCRIPTS +=	pkg_digger_backend pkg_digger pkg_summary2leaves

INSCRIPTS +=	${LIBEXECSCRIPTS}

SCRIPTS =	${INSCRIPTS}

.for i in ${LIBEXECSCRIPTS}
SCRIPTSDIR_${i} =	${LIBEXECDIR}
.endfor

MAN =		pkg_summary-utils.7

MAN +=		pkg_cmp_summary.1 pkg_list_all_pkgs.1
MAN +=		pkg_refresh_summary.1
MAN +=		pkg_micro_src_summary.1 pkg_src_summary.1
MAN +=		pkg_update_src_summary.1 pkg_summary4view.1
MAN +=		pkg_update_summary.1 pkg_grep_summary.1
MAN +=		cvs_checksum.1 # pkg_assignments2pkgpath.1
MAN +=		pkg_uniq_summary.1 # pkg_summary2bb_pkgs.1
MAN +=		pkg_cleanup_distdir.1 pkg_summary2build_graph.1
MAN +=		pkg_summary2deps.1 pkg_lint_summary.1
MAN +=		pkg_subgraph_deps.1 pkg_bin_summary.1
MAN +=		pkg_digger.1 pkg_summary2leaves.1 # pkg_digger_backend.1

FILES =		README NEWS TODO
FILES +=	pkg_grep_summary.awk pkg_src_summary.mk psu_funcs.awk
FILES +=	pkgsrc-dewey.awk pkg_digger.conf

FILESDIR =			${DOCDIR}
FILESDIR_pkg_grep_summary.awk =	${AWKMODDIR}
FILESDIR_psu_funcs.awk =	${AWKMODDIR}
FILESDIR_pkgsrc-dewey.awk =	${AWKMODDIR}
FILESDIR_pkg_src_summary.mk =	${MKSCRIPTSDIR}
FILESDIR_pkg_digger.conf =	${EGDIR}

BIRTHDATE =	2008-04-06

PROJECTNAME =	pkg_summary-utils

INTEXTS_REPLS +=	version      ${VERSION}
INTEXTS_REPLS +=	awkmoddir    ${AWKMODDIR}
INTEXTS_REPLS +=	mkscriptsdir ${MKSCRIPTSDIR}
INTEXTS_REPLS +=	SH           ${SH}
INTEXTS_REPLS +=	AWK          ${AWK}
INTEXTS_REPLS +=	DISTDIR      ${DISTDIR}
INTEXTS_REPLS +=	PKGSRCDIR    ${PKGSRCDIR}
INTEXTS_REPLS +=	BMAKE        ${BMAKE}
INTEXTS_REPLS +=	PKG_SUFX     ${PKG_SUFX}

INTEXTS_SED += -e 's,@PKG_INFO_CMD@,${PKG_INFO_CMD},'

CLEANFILES += ChangeLog

############################################################

DIFF_PROG?=	diff -U10

.PHONY : test
test : all
	@echo 'running tests...'; \
	unset MAKEFLAGS; \
	set -e; cd ${.CURDIR}/tests; \
	env PATH="${.OBJDIR}:$$PATH" OBJDIR=${.OBJDIR} \
		PKGSRCDIR=${PKGSRCDIR} BMAKE=${BMAKE} ./test.sh

############################################################

.include "version.mk"
.include <mkc.prog.mk>
