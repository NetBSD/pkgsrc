# $NetBSD: Makefile,v 1.21 2004/03/05 12:09:35 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-gtk-/}
COMMENT=	Freeciv client with GTK+ interface

DEPENDS+=	freeciv-share>=${FC_VERS}:../../games/freeciv-share
DEPENDS+=	freeciv-sounds>=2.0:../../games/freeciv-sounds

USE_BUILDLINK2=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-server --disable-make-data
CONFIGURE_ARGS+=	--enable-client=gtk
CONFIGURE_ARGS+=	--program-transform-name="s,civclient,civclient-gtk,"

.include "../freeciv-share/Makefile.common"

do-install:
	cd ${WRKSRC}/client; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_TARGET}

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
