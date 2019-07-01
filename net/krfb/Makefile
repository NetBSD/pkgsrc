# $NetBSD: Makefile,v 1.26 2019/07/01 04:08:41 ryoon Exp $

DISTNAME=	krfb-${_KDE_VERSION}
PKGREVISION=	14
CATEGORIES=	net
COMMENT=	KDE desktop sharing

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
