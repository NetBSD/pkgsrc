# $NetBSD: Makefile,v 1.11 2001/08/29 22:41:10 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-client-gtk-/}
COMMENT=		Freeciv client with GTK+ interface

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share

USE_BUILDLINK_ONLY=	# defined

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=gtk
CONFIGURE_ARGS+=	--program-transform-name="s,civclient,civclient-gtk,"

.include "../freeciv-share/Makefile.common"

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
