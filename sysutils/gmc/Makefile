# $NetBSD: Makefile,v 1.26.2.1 2002/06/23 19:00:13 jlam Exp $

PKGNAME=		g${DISTNAME}
PKGREVISION=		1
CATEGORIES+=		gnome

COMMENT=		GNOME version of Midnight Commander, a free Norton Commander Clone

DEPENDS+=		gnome-core>=1.4.0.4nb1:../../x11/gnome-core

USE_X11BASE=		# defined
CONFIGURE_ARGS+=	--with-tm-x-support
CONFIGURE_ARGS+=	--with-gnome
BUILD_USES_MSGFMT=	yes

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gmc/C/figs

.include "../../sysutils/mc/Makefile.common"
