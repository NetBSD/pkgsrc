# $NetBSD: Makefile,v 1.21 2021/11/09 11:28:56 nia Exp $
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
.if exists(/usr/include/net/bpf.h)
PLIST.bpf=		yes
CONFIGURE_ENV+=		ac_cv_epp_bpf=yes
.else
CONFIGURE_ENV+=		ac_cv_epp_bpf=no
.endif

.if exists(/usr/include/net/if_tap.h)
PLIST.tap=		yes
CONFIGURE_ENV+=		ac_cv_epp_tap=yes
.else
CONFIGURE_ENV+=		ac_cv_epp_tap=no
.endif

.if exists(/usr/include/net/if_tun.h) || \
    exists(/usr/include/linux/if_tun.h)
PLIST.tun=		yes
CONFIGURE_ENV+=		ac_cv_epp_tun=yes
.else
CONFIGURE_ENV+=		ac_cv_epp_tun=no
.endif

# override MAKEFLAGS in the build and install stages
do-build:
	cd ${WRKSRC} && ${GMAKE} ${BUILD_TARGET} MAKEFLAGS=

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_TARGET} MAKEFLAGS= DESTDIR=${DESTDIR}

.include "../../devel/libbegemot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
