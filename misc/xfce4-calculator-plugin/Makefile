# $NetBSD: Makefile,v 1.35 2025/02/13 03:20:00 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.7.3
DISTNAME=	xfce4-calculator-plugin-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-calculator-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-calculator-plugin
COMMENT=	Xfce calculator plugin

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
