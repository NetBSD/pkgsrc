# $NetBSD: Makefile,v 1.12 2004/03/09 18:35:13 jmmv Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	9
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
