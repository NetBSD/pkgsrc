# $NetBSD: Makefile,v 1.16 2007/03/17 16:06:22 rillig Exp $
#

DISTNAME=	quirc-0.9.84
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://quirc.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://quirc.org/
COMMENT=	Stable and powerful graphical IRC client

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake automake autoconf autoreconf

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
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
