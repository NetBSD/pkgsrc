# $NetBSD: Makefile,v 1.19 2012/10/03 12:55:16 asau Exp $
#

DISTNAME=	p11-2.10i
CATEGORIES=	emulators
MASTER_SITES=	http://people.freebsd.org/~harti/p11/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@grumpf.hope-2000.org
COMMENT=	PDP11 emulator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-begemot=${PREFIX:Q}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		bpf tap tun

# bfp, tap, and tun tests taken from p11 configure script
.if exists(/dev/bpf0)
PLIST.bpf=		yes
.endif
.if exists(/dev/tap0) || exists(/dev/net/tun)
PLIST.tap=		yes
.endif
.if exists(/dev/tun) || exists(/dev/tun0) || exists(/dev/net/tun)
PLIST.tun=		yes
.endif

# Force the bpf, tun, and tap epp backends to be built on DragonFly.
.if ${OPSYS} == "DragonFly"
PLIST.tap=		yes
PLIST.tun=		yes
CONFIGURE_ENV+=		ac_cv_epp_bpf=yes ac_cv_epp_tun=yes ac_cv_epp_tap=yes
.endif

# override MAKEFLAGS in the build and install stages
do-build:
	cd ${WRKSRC} && ${GMAKE} ${BUILD_TARGET} MAKEFLAGS=

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_TARGET} MAKEFLAGS= DESTDIR=${DESTDIR}

.include "../../devel/libbegemot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
