# $NetBSD: Makefile,v 1.2 2002/03/13 17:36:41 fredb Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	1
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

CONFIGURE_ARGS+= --enable-panel

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
