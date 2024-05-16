# $NetBSD: Makefile,v 1.2 2024/05/16 06:14:53 wiz Exp $

DISTNAME=	ClassiCube-1.3.6
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ClassiCube/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ClassiCube/ClassiCube
COMMENT=	Custom Minecraft Classic client
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

BUILD_TARGET=	default

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/*.c
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_VARS.paths=	PREFIX X11BASE

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-extract:
	dos2unix ${WRKSRC}/src/*.c

post-configure:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/classicube.sh > \
		${WRKDIR}/classicube.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/classicube.sh \
		${DESTDIR}${PREFIX}/bin/classicube
	${INSTALL_DATA} ${FILESDIR}/classicube.desktop \
		${DESTDIR}${PREFIX}/share/applications/classicube.desktop
	${INSTALL_PROGRAM} ${WRKSRC}/ClassiCube \
		${DESTDIR}${PREFIX}/libexec/ClassiCube
	${INSTALL_DATA} ${WRKSRC}/misc/CCicon.png \
		${DESTDIR}${PREFIX}/share/pixmaps/classicube.png

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.  include "../../audio/openal-soft/buildlink3.mk"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../sysutils/desktop-file-utils/desktopdb.mk"
.  include "../../www/curl/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXi/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
