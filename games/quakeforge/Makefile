# $NetBSD: Makefile,v 1.37 2019/07/02 13:37:34 nia Exp $

DISTNAME=		quakeforge-0.5.5
PKGREVISION=		18
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=quake/}

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://www.quakeforge.net/
COMMENT=		Improved Quake engine

CONFIGURE_ARGS+=	--with-cpp=${CPP:Q}" %d %i %o"
CONFIGURE_ARGS+=	--disable-ogg
CONFIGURE_ARGS+=	--disable-xmms
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		bison gmake
USE_LIBTOOL=		YES

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	pre-configure
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	libs/audio/targets/snd_oss.c
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

REPLACE_PYTHON+=	tools/qfcc/source/qfpreqcc

PKG_OPTIONS_VAR=	PKG_OPTIONS.quakeforge
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

PLIST_VARS+=		sunaudio linux
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
PLIST.sunaudio=		yes
.endif

.if ${OPSYS} == "Linux"
PLIST.linux=		yes
.endif

INSTALLATION_DIRS=	include/QF/GL include/QF/plugin include/QF/ruamoko/gui

.include "../../lang/python/application.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
