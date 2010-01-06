# $NetBSD: Makefile,v 1.17 2010/01/06 18:36:14 joerg Exp $
#

DISTNAME=	quirc-0.9.84
PKGREVISION=	3
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

pre-configure:
	cd ${WRKSRC} && autoreconf

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
