# $NetBSD: Makefile,v 1.11 2018/11/14 22:22:04 kleink Exp $

PKGREVISION= 6
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.6.0
DISTNAME=	xfce4-calculator-plugin-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-calculator-plugin/0.6/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-calculator-plugin
COMMENT=	Xfce calculator plugin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
