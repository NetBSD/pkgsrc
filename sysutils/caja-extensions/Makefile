# $NetBSD: Makefile,v 1.67 2026/09/02 19:04:24 wiz Exp $

PKGREVISION= 27
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-extensions-${VERSION:R}.1
CATEGORIES=	sysutils

COMMENT=	Set of extensions for Caja

PKGCONFIG_OVERRIDE+=	sendto/caja-sendto.pc.in

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
