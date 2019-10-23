# $NetBSD: Makefile,v 1.1 2019/10/23 00:21:26 fox Exp $

DISTNAME=	cannonball-0.3.20190924
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=djyt/}
GITHUB_TAG=	a675d7076e3ca5f7f7777e327ed27b04aae43072
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/djyt/cannonball/wiki
COMMENT=	Enhanced OutRun Engine
LICENSE=	mame-license

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes
CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		${WRKSRC}/cmake
CMAKE_ARGS.Linux+=	-DTARGET=debian
CMAKE_ARGS.NetBSD+=	-G "Unix Makefiles"
CMAKE_ARGS.NetBSD+=	-DTARGET=bsd
CMAKE_ARGS.NetBSD+=	-DBSD_PREFIX_PATH:STRING=${PREFIX}

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

ICON_SIZES=	16

INSTALLATION_DIRS+=	bin libexec share/applications \
			share/cannonball share/cannonball/res \
			share/cannonball/conf ${PKGMANDIR}/man6
.for s in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${s}x${s}/apps
.endfor

pre-configure:
.for s in ${ICON_SIZES}
	cd ${WRKSRC} && ${PREFIX}/bin/icotool -w ${s} -h ${s} -x -o ${s}.png \
	   res/cannonball.ico
.endfor

	${MKDIR} ${WRKSRC}/build

post-build:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/cannonball.sh.in > \
	    ${WRKDIR}/cannonball.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/res/tilemap.bin \
	    ${DESTDIR}${PREFIX}/share/cannonball/res/tilemap.bin
	${INSTALL_DATA} ${WRKSRC}/build/res/tilepatch.bin \
	    ${DESTDIR}${PREFIX}/share/cannonball/res/tilepatch.bin
	${INSTALL_DATA} ${WRKSRC}/build/config.xml \
	    ${DESTDIR}${PREFIX}/share/cannonball/conf/config.xml
	${INSTALL_DATA} ${FILESDIR}/cannonball.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${WRKDIR}/cannonball.sh \
	    ${DESTDIR}${PREFIX}/bin/cannonball
	${INSTALL_PROGRAM} ${WRKSRC}/build/cannonball \
	    ${DESTDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/docs/cannonball.6 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
.for s in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/cannonball.png
.endfor

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
