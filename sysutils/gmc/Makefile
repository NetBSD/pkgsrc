# $NetBSD: Makefile,v 1.23 2000/10/19 23:31:15 jlam Exp $

PKGNAME=		g${DISTNAME}
CATEGORIES+=		gnome

DEPENDS+=		gnome-core-*:../../x11/gnome-core

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../sysutils/mc/Makefile.common"
