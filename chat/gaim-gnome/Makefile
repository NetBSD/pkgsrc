# $NetBSD: Makefile,v 1.1 2002/07/09 02:13:27 rafal Exp $

.include "../gaim/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
CONFLICTS+=	gaim-[0-9]*
COMMENT+=	with GNOME support

PLIST_SRC+=	${.CURDIR}/../gaim-gnome/PLIST
MESSAGE_SRC=	${.CURDIR}/../gaim-gnome/MESSAGE

CONFIGURE_ARGS+= --enable-gnome
CONFIGURE_ARGS+= --enable-panel

.include "../../x11/gnome-core/buildlink.mk"
.include "../../audio/esound/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
