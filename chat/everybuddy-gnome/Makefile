# $NetBSD: Makefile,v 1.13 2004/03/26 02:27:35 wiz Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	10
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
