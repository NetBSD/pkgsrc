# $NetBSD: Makefile,v 1.5 2000/09/11 03:53:05 fredb Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext

CONFLICTS=		freeciv-client-gtk-*

USE_X11=		YES
USE_XAW=		YES
USE_XPM=		YES

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=xaw
CPPFLAGS+=		-I${LOCALBASE}/include

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d")
CONFIGURE_ARGS+=	--with-xaw3d
.endif

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../games/freeciv-share/Makefile.common"
