# $NetBSD: Makefile,v 1.4 2001/02/16 15:10:48 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-client-gtk-/}

COMMENT=		Freeciv client with GTK+ interface

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share
BUILD_DEPENDS+=		msgfmt:../../devel/gettext
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		imlib-*:../../graphics/imlib

CONFLICTS=		freeciv-client-[0-9]*

USE_X11=		# defined

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=gtk

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
