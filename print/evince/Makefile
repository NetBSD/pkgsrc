# $NetBSD: Makefile,v 1.14 2006/04/08 21:02:26 reed Exp $
#

.include "../../print/evince/Makefile.common"

COMMENT=		Document viewer for the GNOME Desktop

GCONF2_SCHEMAS=		evince.schemas
GCONF2_SCHEMAS+=	evince-thumbnailer.schemas

.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
