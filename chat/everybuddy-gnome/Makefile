# $NetBSD: Makefile,v 1.4 2002/10/05 17:29:20 wiz Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	2
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

USE_BUILDLINK2=		yes
CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
