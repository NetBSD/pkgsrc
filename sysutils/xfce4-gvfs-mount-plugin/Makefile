# $NetBSD: Makefile,v 1.15 2020/03/08 16:51:26 wiz Exp $

PKGREVISION= 12
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-gvfs-mount-0.0.4-6d2684b
PKGNAME=	xfce4-gvfs-mount-plugin-0.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-gvfs-mount/0.0/

HOMEPAGE=		https://goodies.xfce.org/projects/panel-plugins/xfce4-gvfs-mount
COMMENT=		Xfce gvfs mount plugin

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
