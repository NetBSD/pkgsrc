# $NetBSD: Makefile,v 1.15 2002/09/23 10:02:49 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-client-gtk-/}
PKGREVISION=		1
COMMENT=		Freeciv client with GTK+ interface

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share

USE_BUILDLINK2=		# defined
USE_X11=		# defined

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=gtk
CONFIGURE_ARGS+=	--program-transform-name="s,civclient,civclient-gtk,"

.include "../freeciv-share/Makefile.common"

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
