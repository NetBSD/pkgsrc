# $NetBSD: Makefile,v 1.27 2002/05/30 18:45:00 dmcmahill Exp $

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
