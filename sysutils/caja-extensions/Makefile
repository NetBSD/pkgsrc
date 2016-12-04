# $NetBSD: Makefile,v 1.3 2016/12/04 05:17:41 ryoon Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	caja-extensions-${MATE_VERSION}
CATEGORIES=	sysutils

COMMENT=	Set of extensions for Caja

PKGCONFIG_OVERRIDE+=	sendto/caja-sendto.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../sysutils/caja/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
