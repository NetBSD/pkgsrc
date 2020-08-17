# $NetBSD: Makefile,v 1.30 2020/08/17 20:20:03 leot Exp $

PKGREVISION= 3
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-extensions-${VERSION}
CATEGORIES=	sysutils

COMMENT=	Set of extensions for Caja

PKGCONFIG_OVERRIDE+=	sendto/caja-sendto.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
