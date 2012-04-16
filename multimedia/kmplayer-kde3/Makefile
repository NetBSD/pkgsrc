# $NetBSD: Makefile,v 1.11.2.1 2012/04/16 13:37:30 tron Exp $
#

DISTNAME=	kmplayer-0.10.0c
PKGREVISION=	12
CATEGORIES=	multimedia kde
MASTER_SITES=	http://kmplayer.kde.org/pkgs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kmplayer.kde.org/
COMMENT=	KDE frontend to mplayer

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

DEPENDS+=		mplayer>=1.0rc3:../../multimedia/mplayer
DEPENDS+=		mencoder>=1.0rc3:../../multimedia/mencoder

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt perl pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--without-gstreamer

SHLIBTOOL_OVERRIDE=	# empty

SUBST_CLASSES+=		desktop
SUBST_MESSAGE.desktop=	Fixing application launcher.
SUBST_STAGE.desktop=	pre-configure
SUBST_FILES.desktop=	src/kmplayer.desktop
SUBST_SED.desktop=	-e 's|@PREFIX@|${PREFIX}|g'

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
