# $NetBSD: Makefile,v 1.23 2026/10/24 11:01:52 cheusov Exp $
#

DISTNAME=	runawk-1.6.2
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=runawk/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/runawk
COMMENT=	AWK wrapper that provides support for modules

LICENSE=		mit

USE_LANGUAGES=		c
TEST_TARGET=		test

SUBST_CLASSES+=		runawk
SUBST_SED.runawk=	-e "s,/usr/bin/env runawk,${PREFIX}/bin/runawk,"
SUBST_FILES.runawk=	a_getopt/alt_getopt
SUBST_STAGE.runawk=	pre-build
SUBST_MESSAGE.runawk=	Fixing path to runawk.

EGDIR=		${PREFIX}/share/examples/runawk

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	EGDIR=${EGDIR}
MAKE_ENV+=	SUBPRJ_DFLT='runawk modules a_getopt doc examples'
MAKE_ENV+=	AWK_PROG=${AWK:Q}

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
