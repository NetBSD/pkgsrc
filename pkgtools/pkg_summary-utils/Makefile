# $NetBSD: Makefile,v 1.22 2012/09/11 23:19:38 asau Exp $

DISTNAME=	pkg_summary-utils-0.58.4
CATEGORIES=	pkgtools
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/cheusov/psu/ \
		http://www.mova.org/~cheusov/pub/pkg_summary-utils/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.mova.org/~cheusov/pub/pkg_summary-utils/
COMMENT=	Utilities for manipulating pkg_summary(5) files
LICENSE=	2-clause-bsd

DEPENDS+=	runawk>=1.1.0:../../lang/runawk
DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=	digest-[0-9]*:../../pkgtools/digest

BUILD_DEPENDS+=	mk-configure>=0.20.0:../../devel/mk-configure

CONFLICTS+=	paexec<0.15.0
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

USE_LANGUAGES=		#empty
USE_TOOLS+=		gzip:run

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EGDIR=		${PREFIX}/share/examples/pkg_summary-utils

CONF_FILES=	${EGDIR}/pkg_digger.conf ${PKG_SYSCONFDIR}/pkg_digger.conf

REPLACE_SH=	tests/test.sh pkg_digger.in pkg_digger_backend.in \
		pkg_summary2build_graph.in

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	get_processed_pkgs.in pkg_*.in XB2bin_summary.in \
	direct_deps.in summary2multi_variants.in enrich_summary.in

MAKE_ENV+=	AWKMODDIR=${PREFIX}/share/runawk
MAKE_ENV+=	EGDIR=${EGDIR}
MAKE_ENV+=	SH=${SH:Q}
MAKE_ENV+=	BMAKE=${MAKE:Q}
MAKE_ENV+=	DISTDIR=${DISTDIR}
MAKE_ENV+=	PKGSRCDIR=${PKGSRCDIR}
MAKE_ENV+=	PKG_SUFX=${PKG_SUFX}
MAKE_ENV+=	PKG_INFO_CMD=${PKG_INFO:Q}

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
