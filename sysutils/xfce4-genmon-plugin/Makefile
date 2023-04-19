# $NetBSD: Makefile,v 1.51 2023/04/19 23:53:15 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.2.0
DISTNAME=	xfce4-genmon-plugin-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-genmon-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-genmon-plugin
COMMENT=	Xfce general purpose monitor plugin

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
