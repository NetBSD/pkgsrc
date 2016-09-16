# $NetBSD: Makefile,v 1.4 2016/09/16 11:01:21 richard Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-taskmanager-1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-taskmanager/1.1/

HOMEPAGE=	http://goodies.xfce.org/projects/applications/xfce4-taskmanager
COMMENT=	Xfce task manager

MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-taskmanager/1.1/

# patch needs libkvm.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
LDFLAGS+=	-lkvm
.endif

.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
