# $NetBSD: Makefile,v 1.13 2001/10/23 13:14:52 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-client-/}
COMMENT=		Freeciv client with Xaw interface

DEPENDS+=		freeciv-share-${FC_VERS}:../../games/freeciv-share

CONFLICTS=		freeciv-client-gtk<=1.11.4

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK_ONLY=	# defined

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--disable-make-data
CONFIGURE_ARGS+=	--enable-client=xaw

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-xaw3d
.endif

.include "../freeciv-share/Makefile.common"

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../mk/x11.buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
