# $NetBSD: Makefile,v 1.25 2001/09/27 23:18:43 jlam Exp $

PKGNAME=		g${DISTNAME}
CATEGORIES+=		gnome

COMMENT=		GNOME version of Midnight Commander, a free Norton Commander Clone

DEPENDS+=		gnome-core-[0-9]*:../../x11/gnome-core

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../sysutils/mc/Makefile.common"
