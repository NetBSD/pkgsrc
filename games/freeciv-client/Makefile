# $NetBSD: Makefile,v 1.8 2001/05/02 16:31:09 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}

COMMENT=		Freeciv client with Xaw interface

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share

CONFLICTS=		freeciv-client-gtk<=1.11.4

USE_X11=		YES
USE_XAW=		YES
USE_XPM=		YES

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=xaw

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d")
CONFIGURE_ARGS+=	--with-xaw3d
.endif

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
