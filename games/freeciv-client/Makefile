# $NetBSD: Makefile,v 1.18 2004/03/05 12:07:51 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	Freeciv client with Xaw interface

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share
DEPENDS+=	freeciv-sounds>=2.0:../../games/freeciv-sounds

CONFLICTS=	freeciv-client-gtk<=1.11.4

USE_BUILDLINK2=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-server --disable-make-data
CONFIGURE_ARGS+=	--enable-client=xaw

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-xaw3d
.endif

.include "../freeciv-share/Makefile.common"

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
