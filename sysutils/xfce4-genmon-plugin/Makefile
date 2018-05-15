# $NetBSD: Makefile,v 1.34 2018/05/15 21:55:38 youri Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.0.1
DISTNAME=	xfce4-genmon-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-genmon-plugin/${VERSION:R}/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-genmon-plugin
COMMENT=	Xfce general purpose monitor plugin

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
