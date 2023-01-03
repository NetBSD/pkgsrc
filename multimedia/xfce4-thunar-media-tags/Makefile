# $NetBSD: Makefile,v 1.24 2023/01/03 17:37:59 wiz Exp $

PKGREVISION= 13
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	thunar-media-tags-plugin-0.3.0
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	http://archive.xfce.org/src/thunar-plugins/thunar-media-tags-plugin/0.3/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://goodies.xfce.org/projects/thunar-plugins/thunar-media-tags-plugin
COMMENT=	Thunar media tags plugin

.include "../../audio/taglib/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
