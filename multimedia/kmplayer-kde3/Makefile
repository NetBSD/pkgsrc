# $NetBSD: Makefile,v 1.38 2014/05/05 00:48:11 ryoon Exp $
#

DISTNAME=	kmplayer-0.10.0c
PKGREVISION=	35
CATEGORIES=	multimedia kde
MASTER_SITES=	http://kmplayer.kde.org/pkgs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kmplayer.kde.org/
COMMENT=	KDE frontend to mplayer

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
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
