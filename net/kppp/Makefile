# $NetBSD: Makefile,v 1.11 2015/04/17 15:53:13 adam Exp $

DISTNAME=	kppp-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	net
COMMENT=	Dialer and front end for pppd

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
