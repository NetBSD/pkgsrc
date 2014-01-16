# $NetBSD: Makefile,v 1.48 2014/01/16 10:59:58 martin Exp $
#

DISTNAME=		tme-0.8
PKGREVISION=		23
CATEGORIES=		emulators
MASTER_SITES=		http://csail.mit.edu/~fredette/tme/

MAINTAINER=		pkgsrc-users@NetBSD.org

MAKE_JOBS_SAFE=		no

HOMEPAGE=		http://csail.mit.edu/~fredette/tme/
COMMENT=		The Machine Emulator

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run pkg-config

CONFIGURE_ARGS+=	--disable-debug

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=tautological-compare \
			-Wno-error=sometimes-uninitialized \
			-Wno-error=unused-function
.elif !empty(CC_VERSION:Mgcc-4.8.*)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=unused-but-set-variable	\
	-Wno-error=array-bounds					\
	-fno-strict-aliasing
.endif


.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
