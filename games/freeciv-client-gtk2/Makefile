# $NetBSD: Makefile,v 1.2 2004/04/22 03:54:17 snj Exp $

PKGNAME=	${DISTNAME:S/-/-client-gtk2-/}
COMMENT=	Freeciv client with GTK+ interface

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share
DEPENDS+=	freeciv-sounds>=2.0:../../games/freeciv-sounds

USE_X11=		yes

CONFIGURE_ARGS+=	--disable-server --disable-make-data
CONFIGURE_ARGS+=	--enable-client=gtk2
CONFIGURE_ARGS+=	--program-transform-name="s,civclient,civclient-gtk2,"

.include "../freeciv-share/Makefile.common"

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
