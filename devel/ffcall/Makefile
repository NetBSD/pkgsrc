# $NetBSD: Makefile,v 1.15 2004/02/03 01:43:32 grant Exp $

DISTNAME=	ffcall-1.8d
PKGNAME=	ffcall-1.8.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=libs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.haible.de/bruno/packages-ffcall.html
COMMENT=	Foreign function call libraries

# the file ${WRKDIR}/ffcall-1.8/avcall/avcall-${MACHINE_ARCH}.c needs to
# be added for additional port support.
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm *-*-i386 *-*-m68k *-*-sparc *-*-sparc64 *-*-powerpc

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../mk/bsd.prefs.mk"

# Gnustep requires this by linking ffcall libs into libgnustep-base.so
# Only tested on powerpc.
.if (${MACHINE_ARCH} == "powerpc" && ${OPSYS} == "NetBSD")
CONFIGURE_ARGS+=	--enable-shared
PLIST_SRC+=		PLIST.shared

post-install:
	${LN} -sf ../lib/libavcall.so.0.0 ${PREFIX}/lib/libavcall.so.0
	${LN} -sf ../lib/libavcall.so.0.0 ${PREFIX}/lib/libavcall.so
	${LN} -sf ../lib/libcallback.so.0.0 ${PREFIX}/lib/libcallback.so.0
	${LN} -sf ../lib/libcallback.so.0.0 ${PREFIX}/lib/libcallback.so
.endif

post-patch:
	${CP} files/tramp-rs6000-netbsd.s ${WRKSRC}/callback/trampoline_r
	${CP} files/vacall-rs6000-netbsd.s ${WRKSRC}/callback/vacall_r

#
# Run the supplied tests to sanity check everything
#
post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} check

.include "../../mk/bsd.pkg.mk"
