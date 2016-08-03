# $NetBSD: Makefile,v 1.3 2016/08/03 10:23:26 adam Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-taskmanager-1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-taskmanager/1.1/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-taskmanager
COMMENT=	Xfce task manager

MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-taskmanager/1.1/

# patch needs libkvm.
LDFLAGS+=	-lkvm

.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
