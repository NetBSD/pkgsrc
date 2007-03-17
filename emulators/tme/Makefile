# $NetBSD: Makefile,v 1.14 2007/03/17 13:44:17 tsutsui Exp $
#

DISTNAME=		tme-0.4
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		http://theory.lcs.mit.edu/~fredette/tme/

MAINTAINER=		skrll@NetBSD.org
# Please do not assign PR's for this package to skrll.
# Instead, assign them to the package author, fredette.

HOMEPAGE=		http://theory.lcs.mit.edu/~fredette/tme/
COMMENT=		The Machine Emulator

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	ac_cv_shiftmax_int8_t=8
CONFIGURE_ARGS+=	ac_cv_shiftmax_int16_t=16
CONFIGURE_ARGS+=	ac_cv_shiftmax_int32_t=32

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
