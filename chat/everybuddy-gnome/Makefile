# $NetBSD: Makefile,v 1.7 2003/05/02 11:54:01 wiz Exp $

.include "../everybuddy/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	5
CONFLICTS+=	everybuddy-[0-9]*
COMMENT+=	with GNOME support

USE_BUILDLINK2=		yes
CONFIGURE_ARGS+=	--enable-panel

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
