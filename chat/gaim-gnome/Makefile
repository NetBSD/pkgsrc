# $NetBSD: Makefile,v 1.10 2004/01/03 18:49:35 reed Exp $

.include "../gaim-gtk1/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	6
CONFLICTS+=	gaim-[0-9]*
COMMENT+=	with GNOME support

PLIST_SRC+=	${.CURDIR}/../gaim-gnome/PLIST
MESSAGE_SRC=	${.CURDIR}/../gaim-gnome/MESSAGE

CONFIGURE_ARGS+= --enable-gnome
CONFIGURE_ARGS+= --enable-panel

USE_BUILDLINK2=	YES

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
