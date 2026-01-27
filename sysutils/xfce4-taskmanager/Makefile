# $NetBSD: Makefile,v 1.46 2026/01/27 08:40:40 wiz Exp $

PKGREVISION= 4
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.5.8
DISTNAME=	xfce4-taskmanager-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-taskmanager/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfce4-taskmanager
COMMENT=	Xfce task manager

# NetBSD support file needs libkvm.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
LDFLAGS+=	-lkvm
.endif

.if ${OPSYS} == "NetBSD"
pre-configure:
	${CP} ${FILESDIR}/task-manager-netbsd.c ${WRKSRC}/src/task-manager-bsd.c
.endif

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../graphics/adwaita-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
