# $NetBSD: Makefile,v 1.4 2007/12/30 09:37:23 hira Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.5.0

DISTNAME=	xfce4-battery-plugin-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-battery-plugin/
COMMENT=	Xfce battey monitor plugin

.if ${OPSYS} == "NetBSD" && !exists(/usr/include/machine/apmvar.h)
PKG_FAIL_REASON+=	"APM is not available on ${MACHINE_PLATFORM}."
.endif

USE_TOOLS+=	perl:run

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
