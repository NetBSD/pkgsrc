# $NetBSD: Makefile,v 1.43 2008/01/25 12:10:57 tnn Exp $

DISTNAME=		icon.v942src
PKGNAME=		icon-9.4.2
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/icon/index.htm
COMMENT=		The Icon programming language

CONFIGURE_TARGET=	X-Configure
BUILD_TARGET=		All
TEST_TARGET=		Test
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "NetBSD"
NAME=	netbsd
.  if (${MACHINE_ARCH} == "alpha") || (${MACHINE_ARCH} == "i386") || \
	(${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "powerpc") || \
	(${MACHINE_ARCH} == "mipseb") || (${MACHINE_ARCH} == "mipsel") || \
	(${MACHINE_ARCH} == "m68k") || (${MACHINE_ARCH} == "vax")
.  else
PTHREAD_OPTS+=		require native
.  include "../../mk/pthread.buildlink3.mk"
.  endif

.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
NAME=	freebsd

.elif ${OPSYS} == "SunOS"

.  if !empty(CC_VERSION:M*gcc*)
NAME=	sun_gcc
.  elif !empty(CC_VERSION:MSun)
NAME=	sun_sunc
.  else
PKG_FAIL_REASON+=	"${PKGNAME} does not know about "${CC_VERSION:Q}
.  endif

.  if ${MACHINE_ARCH} == "sparc"
.  else
PTHREAD_OPTS+=		require native
.  include "../../mk/pthread.buildlink3.mk"
.  endif

.else
PKG_FAIL_REASON+=	"${PKGNAME} does not have the correct config name for this system"
.endif

pre-build:
	${MKDIR} ${WRKSRC}/lib/icon

do-configure:
	cd ${WRKSRC}/config/netbsd && \
	${SED} -e 's:@X11BASE@:${X11BASE}:g' define.h.in \
		> define.h
	cd ${WRKSRC} && ${MAKE} ${CONFIGURE_TARGET} name=${NAME}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} dest=${PREFIX} Install

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
