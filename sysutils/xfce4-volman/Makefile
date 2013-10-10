# $NetBSD: Makefile,v 1.29 2013/10/10 14:42:33 ryoon Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.0

DISTNAME=	thunar-volman-${XFCE4_VERSION}
PKGNAME=	${DISTNAME:S/thunar/xfce4/}
PKGREVISION=	24
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/thunar-volman/
COMMENT=	Thunar volume manager


.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
