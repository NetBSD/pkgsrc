# $NetBSD: Makefile,v 1.50 2010/04/10 04:09:21 markd Exp $
#

DISTNAME=	kmplayer-0.11.2a
CATEGORIES=	multimedia kde
MASTER_SITES=	http://kmplayer.kde.org/pkgs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kmplayer.kde.org/
COMMENT=	KDE frontend to mplayer

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		mplayer>=1.0rc3:../../multimedia/mplayer
DEPENDS+=		mencoder>=1.0rc3:../../multimedia/mencoder

USE_CMAKE=		yes
USE_TOOLS+=		msgfmt perl pkg-config
USE_LANGUAGES=		c c++

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
