# $NetBSD: Makefile,v 1.45 2024/06/15 09:38:55 cheusov Exp $

DISTNAME=	pkg_summary-utils-0.69.0
CATEGORIES=	pkgtools
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cheusov/psu/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/pkg_summary-utils
COMMENT=	Utilities for manipulating pkg_summary(5) files
LICENSE=	2-clause-bsd

DEPENDS+=	paexec>=0.19.1:../../parallel/paexec
DEPENDS+=	runawk>=1.1.0:../../lang/runawk
DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

TOOL_DEPENDS+=	mk-configure>=0.26.0:../../devel/mk-configure

CONFLICTS+=	awk-pkgsrc-dewey-[0-9]*
CONFLICTS+=	pkg_src_summary-[0-9]*
CONFLICTS+=	pkg_cmp_summary-[0-9]*
CONFLICTS+=	pkg_src_update_summary-[0-9]*
CONFLICTS+=	pkg_update_summary-[0-9]*
CONFLICTS+=	pkg_summary4view-[0-9]*

# usage:
#    bmake test
#    bmake test TESTS='show-tests'
#    bmake test TESTS='pkg_subgraph_deps pkg_bin_summary ...'
TEST_TARGET=		test

BUILD_TARGET=		all all-doc
INSTALL_TARGET=		install install-doc

USE_LANGUAGES=		c
USE_TOOLS+=		gzip:run

EGDIR=		${PREFIX}/share/examples/pkg_summary-utils

CONF_FILES=	${EGDIR}/pkg_digger.conf ${PKG_SYSCONFDIR}/pkg_digger.conf

REPLACE_SH=	tests/test.sh scripts/pkg_digger.in \
		scripts/pkg_summary2build_graph.in

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	scripts/get_processed_pkgs.in scripts/pkg_*.in \
			scripts/XB2bin_summary.in scripts/direct_deps.in \
			scripts/summary2multi_variants.in scripts/enrich_summary.in \
			scripts/makefiles2deps.in

MAKE_ENV+=	AWKMODDIR=${PREFIX}/share/runawk
MAKE_ENV+=	EGDIR=${EGDIR}
MAKE_ENV+=	SH=${SH:Q}
MAKE_ENV+=	BMAKE=${MAKE:Q}
MAKE_ENV+=	DISTDIR=${DISTDIR}
MAKE_ENV+=	PKGSRCDIR=${PKGSRCDIR}
MAKE_ENV+=	PKG_SUFX=${PKG_SUFX}
MAKE_ENV+=	PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}
MAKE_ENV+=	PKG_DBDIR=${PKG_DBDIR}

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
