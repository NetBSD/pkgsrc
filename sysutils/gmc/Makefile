# $NetBSD: Makefile,v 1.24 2001/02/17 17:42:13 wiz Exp $

PKGNAME=		g${DISTNAME}
CATEGORIES+=		gnome

COMMENT=		GNOME version of Midnight Commander, a free Norton Commander Clone

DEPENDS+=		gnome-core-*:../../x11/gnome-core

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../sysutils/mc/Makefile.common"
