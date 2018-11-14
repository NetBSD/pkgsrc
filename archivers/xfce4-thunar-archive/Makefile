# $NetBSD: Makefile,v 1.13 2018/11/14 22:20:59 kleink Exp $
#

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	thunar-archive-plugin-0.4.0
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	http://archive.xfce.org/src/thunar-plugins/thunar-archive-plugin/0.4/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://goodies.xfce.org/projects/thunar-plugins/thunar-archive-plugin
COMMENT=	Thunar archive plugin

DEPENDS=	file-roller-[0-9]*:../../archivers/file-roller

.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
