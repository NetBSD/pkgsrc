# $NetBSD: Makefile,v 1.2 2000/08/12 06:34:35 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-client-gtk-/}

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		imlib-*:../../graphics/imlib

CONFLICTS=		freeciv-client-[0-9]*

USE_X11=		# defined

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=gtk
CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
