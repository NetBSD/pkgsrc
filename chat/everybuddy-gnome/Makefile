# $NetBSD: Makefile,v 1.8 2003/07/13 13:50:44 wiz Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	6
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

USE_BUILDLINK2=		yes
CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
