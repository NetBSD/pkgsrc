# $NetBSD: Makefile,v 1.58 2011/11/01 06:02:13 sbd Exp $
#

DISTNAME=	kmplayer-0.11.2c
PKGREVISION=	4
CATEGORIES=	multimedia kde
MASTER_SITES=	http://kmplayer.kde.org/pkgs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kmplayer.kde.org/
COMMENT=	KDE frontend to mplayer

BUILD_DEPENDS+=		automoc4>=0.9.87:../../devel/automoc4
DEPENDS+=		mplayer>=1.0rc3:../../multimedia/mplayer
DEPENDS+=		mencoder>=1.0rc3:../../multimedia/mencoder

PKG_DESTDIR_SUPPORT=	user-destdir

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
