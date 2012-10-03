# $NetBSD: Makefile,v 1.20 2012/10/03 00:02:43 asau Exp $
#

DISTNAME=	quirc-0.9.84
PKGREVISION=	4
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

SUBST_CLASSES+=		T85
SUBST_STAGE.T85=	post-patch
SUBST_FILES.T85=	configure configure.in
SUBST_MESSAGE.T85=	Changing tcl/tk 8.3 search into tcl/tk 8.5 search
SUBST_SED.T85=		-e 's,8_3,8_5,g' -e 's,8.3,8.5,g' -e 's,83,85,g'

pre-configure:
	cd ${WRKSRC} && autoreconf

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
