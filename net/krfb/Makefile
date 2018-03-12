# $NetBSD: Makefile,v 1.22 2018/03/12 11:17:20 wiz Exp $

DISTNAME=	krfb-${_KDE_VERSION}
PKGREVISION=	10
CATEGORIES=	net
COMMENT=	KDE desktop sharing

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
