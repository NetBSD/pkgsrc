# $NetBSD: Makefile,v 1.2 2000/04/07 18:43:22 hubertf Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}

DEPENDS+=		freeciv-share-1.10.0:../../games/freeciv-share
DEPENDS+=		xpm-*:../../graphics/xpm

CONFLICTS=		freeciv-client-gtk-*

USE_XAW=		# defined
USE_X11=		# defined

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-server --disable-make-data
CONFIGURE_ARGS+=	--enable-client=xaw

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d")
CONFIGURE_ARGS+=	--with-xaw3d
.endif

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
