# $NetBSD: Makefile,v 1.9 2003/11/12 01:31:47 salo Exp $

.include "../gaim-gtk1/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	5
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
