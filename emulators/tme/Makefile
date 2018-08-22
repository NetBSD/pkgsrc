# $NetBSD: Makefile,v 1.67 2018/08/22 09:45:05 wiz Exp $
#

DISTNAME=		tme-0.8
PKGREVISION=		35
CATEGORIES=		emulators
MASTER_SITES=		http://csail.mit.edu/~fredette/tme/

MAINTAINER=		pkgsrc-users@NetBSD.org

MAKE_JOBS_SAFE=		no

HOMEPAGE=		http://csail.mit.edu/~fredette/tme/
COMMENT=		The Machine Emulator

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run pkg-config yacc

CONFIGURE_ARGS+=	--disable-debug
# XXX Turn off -Werror for now; there are a very very large number of
# warnings generated, increasing with every compiler version.
CONFIGURE_ARGS+=	--disable-warnings

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.[89].*) || !empty(CC_VERSION:Mgcc-[56789].*)
_WRAP_EXTRA_ARGS.CC+= -fno-strict-aliasing
CWRAPPERS_APPEND.cc+= -fno-strict-aliasing
.endif

PLIST_VARS+=	bsd
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly"
PLIST.bsd=	yes
.endif

.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
