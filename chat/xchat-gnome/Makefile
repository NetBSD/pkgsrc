# $NetBSD: Makefile,v 1.4 2002/11/29 09:01:19 tron Exp $

.include "../xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
CONFLICTS+=	xchat-[0-9]*
COMMENT+=	and GNOME libraries

CONFIGURE_ARGS+=	--enable-panel

.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
