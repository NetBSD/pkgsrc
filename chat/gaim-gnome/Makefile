# $NetBSD: Makefile,v 1.15 2004/10/03 00:13:14 tv Exp $

.include "../gaim-gtk1/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	10
CONFLICTS+=	gaim-[0-9]*
COMMENT+=	with GNOME support

PLIST_SRC+=	${.CURDIR}/../gaim-gnome/PLIST
MESSAGE_SRC=	${.CURDIR}/../gaim-gnome/MESSAGE

CONFIGURE_ARGS+= --enable-gnome
CONFIGURE_ARGS+= --enable-panel

USE_BUILDLINK3=	YES

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
