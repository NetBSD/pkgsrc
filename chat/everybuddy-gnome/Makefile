# $NetBSD: Makefile,v 1.16 2004/11/30 18:26:39 wiz Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	12
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
