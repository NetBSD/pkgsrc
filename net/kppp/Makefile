# $NetBSD: Makefile,v 1.13 2016/01/10 19:19:30 markd Exp $

DISTNAME=	kppp-15.12.0
CATEGORIES=	net
COMMENT=	Dialer and front end for pppd
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
