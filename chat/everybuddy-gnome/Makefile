# $NetBSD: Makefile,v 1.1.1.1 2001/12/19 14:10:04 tron Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

CONFIGURE_ARGS+= --enable-panel

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
