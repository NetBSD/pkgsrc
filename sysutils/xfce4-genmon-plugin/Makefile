# $NetBSD: Makefile,v 1.35 2018/08/22 09:46:42 wiz Exp $

PKGREVISION= 1
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
