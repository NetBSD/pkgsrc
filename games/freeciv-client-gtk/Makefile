# $NetBSD: Makefile,v 1.1.1.1 2000/03/28 00:35:49 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-client-gtk-/}

DEPENDS+=		freeciv-share-1.10.0:../../games/freeciv-share
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		imlib-*:../../graphics/imlib

CONFLICTS=		freeciv-client-[0-9]*

USE_X11=		# defined

CONFIGURE_ARGS+=	--disable-server --disable-make-data
CONFIGURE_ARGS+=	--enable-client=gtk

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
