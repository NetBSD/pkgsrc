# $NetBSD: Makefile,v 1.3 2016/08/03 10:22:26 adam Exp $
#

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	thunar-archive-plugin-0.3.1
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	http://archive.xfce.org/src/thunar-plugins/thunar-archive-plugin/0.3/

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://goodies.xfce.org/projects/thunar-plugins/thunar-archive-plugin
COMMENT=	Thunar archive plugin

DEPENDS=	file-roller-[0-9]*:../../archivers/file-roller

.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
