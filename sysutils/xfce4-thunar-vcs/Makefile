# $NetBSD: Makefile,v 1.38 2022/04/18 19:12:08 adam Exp $

PKGREVISION= 14
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.2.0
DISTNAME=	thunar-vcs-plugin-${VERSION}
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://archive.xfce.org/src/thunar-plugins/thunar-vcs-plugin/${VERSION:R}/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://goodies.xfce.org/projects/thunar-plugins/thunar-vcs-plugin
COMMENT=	Thunar vcs integration plugin

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
