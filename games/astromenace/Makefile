# $NetBSD: Makefile,v 1.9 2022/08/11 05:08:23 gutteridge Exp $

DISTNAME=	astromenace-1.4.1
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=viewizard/}
GITHUB_PROJECT=	astromenace
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://viewizard.com/
COMMENT=	Hardcore 3D space scroll-shooter
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v4.0 AND ofl-v1.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

OBJDIR=			build
CONFIGURE_DIRS=		${OBJDIR}
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=		-DDATADIR=${PREFIX}/share/astromenace

ICON_SIZES=		64 128

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/astromenace
.for s in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${s}x${s}/apps
.endfor

pre-configure:
	${MKDIR} ${WRKSRC}/${OBJDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OBJDIR}/astromenace \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${OBJDIR}/gamedata.vfs \
		${DESTDIR}${PREFIX}/share/astromenace
	${INSTALL_DATA} ${WRKSRC}/share/astromenace.desktop \
		${DESTDIR}${PREFIX}/share/applications
.for s in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/share/astromenace_${s}.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/astromenace.png
.endfor

.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
