# $NetBSD: Makefile,v 1.27 2014/02/04 00:12:07 joerg Exp $
#

DISTNAME=	quirc-0.9.84
PKGREVISION=	8
CATEGORIES=	chat
MASTER_SITES=	http://quirc.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://quirc.org/
COMMENT=	Stable and powerful graphical IRC client

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake automake autoconf autoreconf wish

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-wish=${TOOLS_PATH.wish}
MAKE_FLAGS+=	docdir=${PREFIX}/share/doc/quirc

SUBST_CLASSES+=		T86
SUBST_STAGE.T86=	post-patch
SUBST_FILES.T86=	configure configure.in
SUBST_MESSAGE.T86=	Changing tcl/tk 8.3 search into tcl/tk 8.6 search
SUBST_SED.T86=		-e 's,8_3,8_6,g'
SUBST_SED.T86+=		-e 's,8.3,8.6,g'
SUBST_SED.T86+=		-e 's,83,86,g'

pre-configure:
	cd ${WRKSRC} && autoreconf -i

BUILDLINK_DEPMETHOD.libXt?=	build

CPPFLAGS+=	-DUSE_INTERP_RESULT

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
