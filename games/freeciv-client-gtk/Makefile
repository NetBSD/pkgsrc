# $NetBSD: Makefile,v 1.7 2001/05/02 16:32:41 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-client-gtk-/}nb1

COMMENT=		Freeciv client with GTK+ interface

BUILD_USES_MSGFMT=	yes
DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		imlib-*:../../graphics/imlib

USE_X11=		# defined

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=gtk
CONFIGURE_ARGS+=	--program-transform-name="s,civclient,civclient-gtk,"

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
