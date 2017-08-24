# $NetBSD: Makefile,v 1.20 2017/08/24 20:03:36 adam Exp $

DISTNAME=	krfb-${_KDE_VERSION}
PKGREVISION=	8
CATEGORIES=	net
COMMENT=	KDE desktop sharing

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
