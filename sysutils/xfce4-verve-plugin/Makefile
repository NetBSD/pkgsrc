# $NetBSD: Makefile,v 1.33 2023/11/14 14:02:57 wiz Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-verve-plugin-2.0.3
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-verve-plugin/2.0/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-verve-plugin
COMMENT=	Xfce command line plugin

.include "../../devel/pcre2/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
