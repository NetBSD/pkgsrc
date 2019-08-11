# $NetBSD: Makefile,v 1.18 2019/08/11 13:23:20 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-taskmanager-1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/apps/xfce4-taskmanager/1.2/

HOMEPAGE=	https://goodies.xfce.org/projects/applications/xfce4-taskmanager
COMMENT=	Xfce task manager

# patch needs libkvm.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
LDFLAGS+=	-lkvm
.endif

CONFIGURE_ARGS+=	--disable-gtk2
.if ${OPSYS} == "NetBSD"
pre-configure:
	${CP} ${FILESDIR}/task-manager-netbsd.c ${WRKSRC}/src/task-manager-bsd.c
.endif

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
