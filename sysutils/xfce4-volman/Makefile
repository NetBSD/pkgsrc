# $NetBSD: Makefile,v 1.11 2011/11/01 06:02:37 sbd Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.0

DISTNAME=	thunar-volman-${XFCE4_VERSION}
PKGNAME=	${DISTNAME:S/thunar/xfce4/}
PKGREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/thunar-volman/
COMMENT=	Thunar volume manager


.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../sysutils/xfce4-thunar/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
