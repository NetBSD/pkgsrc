# $NetBSD: Makefile,v 1.1 2026/09/09 03:53:52 charlotte Exp $

DISTNAME=	billyfrontier-1.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/billy/
COMMENT=	Source port of Billy Frontier from Pangea Software
LICENSE=	cc-by-nc-sa-v4.0-license

GITHUB_SUBMODULES=	\
	jorio Pomme 9fae17d7715314a3a20259ac2e87aa500a977695 extern/Pomme

WRKSRC=		${WRKDIR}/BillyFrontier-${PKGVERSION_NOREV}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

USE_CXX_FEATURES+=	has_include

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/billyfrontier/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/billyfrontier.template > ${WRKDIR}/billyfontier

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/billyfontier ${DESTDIR}${PREFIX}/bin/billyfontier
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/BillyFrontier ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/billyfrontier/Data)

.include "../../devel/cmake/build.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
