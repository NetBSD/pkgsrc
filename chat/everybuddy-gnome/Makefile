# $NetBSD: Makefile,v 1.5 2002/12/24 06:09:45 wiz Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	3
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

USE_BUILDLINK2=		yes
CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
