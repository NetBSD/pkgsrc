# $NetBSD: Makefile,v 1.32 2012/12/16 01:52:26 obache Exp $
#

DISTNAME=	kaffeine-0.8.3
PKGREVISION=	25
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kaffeine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kaffeine.sourceforge.net/
COMMENT=	Full featured Multimedia-Player for KDE

GNU_CONFIGURE=		yes
SET_LIBDIR=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt perl pkg-config

CONFIGURE_ARGS+=	--without-gstreamer
CONFIGURE_ARGS+=	--without-dpms
CONFIGURE_ARGS+=	--without-xinerama
CONFIGURE_ARGS+=	--without-dvb

BUILDLINK_FNAME_TRANSFORM.cdparanoia+=	-e "s|/cdparanoia/|/|g"

# Hardcoded paths for libdvdcss and win32-codecs
SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	kaffeine/src/instwizard.cpp
SUBST_SED.path=		-e "s|/usr/lib|${PREFIX}/lib|g"
SUBST_MESSAGE.path=	Fixing hardcoded paths.

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
