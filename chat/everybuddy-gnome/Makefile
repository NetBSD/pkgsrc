# $NetBSD: Makefile,v 1.9 2003/08/15 22:48:04 jmc Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	6
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
