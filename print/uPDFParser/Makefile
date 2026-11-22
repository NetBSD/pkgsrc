# $NetBSD: Makefile,v 1.1 2026/11/22 14:58:00 wiz Exp $

DISTNAME=	v0.1
PKGNAME=	uPDFParser-${DISTNAME:S,^v,,}
CATEGORIES=	print
MASTER_SITES=	https://forge.soutade.fr/soutade/uPDFParser/archive/
DIST_SUBDIR=	uPDFParser

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forge.soutade.fr/soutade/updfparser
COMMENT=	Very simple PDF parser to load PDF objects without interpretation
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/updfparser
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
# just builds a test binary
#TEST_TARGET=	test
MAKE_FLAGS+=	BUILD_SHARED=1
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	include lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/*.so ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
