# $NetBSD: Makefile,v 1.47 2023/11/12 13:23:30 wiz Exp $

PKGREVISION= 8
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-extensions-${VERSION:R}.1
CATEGORIES=	sysutils

COMMENT=	Set of extensions for Caja

PKGCONFIG_OVERRIDE+=	sendto/caja-sendto.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
