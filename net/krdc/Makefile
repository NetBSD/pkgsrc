# $NetBSD: Makefile,v 1.22 2018/03/12 11:17:20 wiz Exp $

DISTNAME=	krdc-15.12.0
PKGREVISION=	9
CATEGORIES=	net
COMMENT=	KDE remote desktop client
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../net/libvncserver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
