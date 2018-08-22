# $NetBSD: Makefile,v 1.8 2018/08/22 09:46:42 wiz Exp $

PKGREVISION= 7
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=		xfce4-gvfs-mount-0.0.4-6d2684b
PKGNAME=		xfce4-gvfs-mount-plugin-0.0.4
CATEGORIES=		sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-gvfs-mount/0.0/

HOMEPAGE=		http://goodies.xfce.org/projects/panel-plugins/xfce4-gvfs-mount
COMMENT=		Xfce gvfs mount plugin

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
