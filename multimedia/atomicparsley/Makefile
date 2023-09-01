# $NetBSD: Makefile,v 1.4 2023/09/01 10:08:46 nia Exp $

GITHUB_PROJECT=	atomicparsley
GITHUB_TAG=	refs/tags/20221229.172126.d813aa6
DISTNAME=	20221229.172126.d813aa6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:C:\..*::}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=wez/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wez/atomicparsley/
COMMENT=	Tool to read, parse and set metadata into MPEG-4 files
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/atomicparsley-20221229.172126.d813aa6
USE_LANGUAGES=	c c++

# Uses nullptr in the code without setting -std=XX.
FORCE_CXX_STD+=		c++11
USE_CXX_FEATURES+=	c++11

INSTALLATION_DIRS=	share/doc/atomicparsley

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/atomicparsley
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESTDIR}${PREFIX}/share/doc/atomicparsley
	${INSTALL_DATA} ${WRKSRC}/Changes.txt ${DESTDIR}${PREFIX}/share/doc/atomicparsley
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/atomicparsley

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
