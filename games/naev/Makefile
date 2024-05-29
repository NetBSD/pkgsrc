# $NetBSD: Makefile,v 1.28 2024/05/29 16:32:42 adam Exp $

DISTNAME=	naev-0.7.0
PKGREVISION=	27
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=naev/}
GITHUB_TAG=	naev-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/naev/naev
COMMENT=	2D space trading and combat game
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

TOOL_DEPENDS+=	zip-[0-9]*:../../archivers/zip

BUILD_TARGET=	all ndata.zip
INSTALL_TARGET=	install install-ndata

CONFIGURE_ARGS+=	--enable-debug=no
CONFIGURE_ARGS+=	--enable-lua=shared
CONFIGURE_ARGS+=	--disable-sdltest

SUBST_CLASSES+=		ndata
SUBST_STAGE.ndata=	pre-configure
SUBST_FILES.ndata=	src/ndata.c
SUBST_SED.ndata=	-e "s,@DATADIR@,${PREFIX}/share/naev,"

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../archivers/libzip/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
