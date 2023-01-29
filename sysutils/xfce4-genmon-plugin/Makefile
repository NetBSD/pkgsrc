# $NetBSD: Makefile,v 1.50 2023/01/29 21:17:52 ryoon Exp $

PKGREVISION= 4
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.1.1
DISTNAME=	xfce4-genmon-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-genmon-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-genmon-plugin
COMMENT=	Xfce general purpose monitor plugin

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
