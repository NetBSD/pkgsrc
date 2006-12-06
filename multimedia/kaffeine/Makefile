# $NetBSD: Makefile,v 1.1.1.1 2006/12/06 18:30:11 xtraeme Exp $
#

DISTNAME=	kaffeine-0.8.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kaffeine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://kaffeine.sourceforge.net/
COMMENT=	Full featured Multimedia-Player for KDE

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt perl pkg-config

CONFIGURE_ARGS+=	--without-gstreamer
CONFIGURE_ARGS+=	--without-dpms
CONFIGURE_ARGS+=	--without-xinerama
CONFIGURE_ARGS+=	--without-dvb

BUILDLINK_TRANSFORM.cdparanoia+=	-e "s|/cdparanoia/|/|g"
BUILDLINK_TRANSFORM+=			l:jpeg6b:jpeg

# Detection of libjpeg6b
SUBST_CLASSES+=		local
SUBST_STAGE.local=	pre-configure
SUBST_FILES.local=	configure
SUBST_SED.local=	-e "s|/usr/local|${PREFIX}|g"

# Hardcoded paths for libdvdcss and win32-codecs
SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	kaffeine/src/instwizard.cpp
SUBST_SED.path=		-e "s|/usr/lib|${PREFIX}/lib|g"
SUBST_MESSAGE.path=	Fixing hardcoded paths.

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
