# $NetBSD: Makefile,v 1.5 2002/12/24 06:09:47 wiz Exp $

.include "../xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	1
CONFLICTS+=	xchat-[0-9]*
COMMENT+=	and GNOME libraries

CONFIGURE_ARGS+=	--enable-panel

.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
