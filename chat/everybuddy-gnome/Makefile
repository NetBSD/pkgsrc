# $NetBSD: Makefile,v 1.14 2004/04/26 05:32:00 snj Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	10
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
