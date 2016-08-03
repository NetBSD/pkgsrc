# $NetBSD: Makefile,v 1.27 2016/08/03 10:23:26 adam Exp $

PKGREVISION= 2
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	3.4
DISTNAME=	xfce4-genmon-plugin-${VERSION}.0
PKGNAME=	xfce4-genmon-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-genmon-plugin/3.4/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-genmon-plugin
COMMENT=	Xfce general purpose monitor plugin

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
