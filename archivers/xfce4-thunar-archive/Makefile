# $NetBSD: Makefile,v 1.38 2025/03/12 21:53:47 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	thunar-archive-plugin-0.5.3
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	https://archive.xfce.org/src/thunar-plugins/thunar-archive-plugin/0.5/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://goodies.xfce.org/projects/thunar-plugins/thunar-archive-plugin
COMMENT=	Thunar archive plugin

DEPENDS=	xarchiver-[0-9]*:../../archivers/xarchiver

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
