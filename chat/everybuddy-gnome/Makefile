# $NetBSD: Makefile,v 1.3 2002/09/10 16:06:33 wiz Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	2
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

CONFIGURE_ARGS+= --enable-panel

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
