# $NetBSD: Makefile,v 1.9 2003/10/03 07:43:11 xtraeme Exp $

.include "../xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
# Don't set "PKGREVISION" here, set it in "../xchat/Makefile.common".
CONFLICTS+=	xchat-1.[0-9]*
COMMENT+=	and GNOME libraries

CONFIGURE_ARGS+=	--enable-panel

.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
