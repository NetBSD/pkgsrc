# $NetBSD: Makefile,v 1.23 2018/04/29 21:31:59 adam Exp $

DISTNAME=	krfb-${_KDE_VERSION}
PKGREVISION=	11
CATEGORIES=	net
COMMENT=	KDE desktop sharing

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
