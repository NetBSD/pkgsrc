# $NetBSD: Makefile,v 1.12 2004/10/07 09:04:33 tron Exp $

.include "../xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
# Don't set "PKGREVISION" here, set it in "../xchat/Makefile.common".
CONFLICTS+=	xchat-[0-9]*
COMMENT+=	and GNOME libraries

CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
