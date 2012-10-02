# $NetBSD: Makefile,v 1.50 2012/10/02 20:11:42 asau Exp $

DISTNAME=		icon.v943src
PKGNAME=		icon-9.4.3
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/icon/index.htm
COMMENT=		The Icon programming language
LICENSE=		public-domain

CONFIGURE_TARGET=	X-Configure
BUILD_TARGET=		All
INSTALL_TARGET=		Install
TEST_TARGET=		Test
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "NetBSD"
NAME=	bsd
.  if (${MACHINE_ARCH} == "alpha") || (${MACHINE_ARCH} == "i386") || \
	(${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "powerpc") || \
	(${MACHINE_ARCH} == "mipseb") || (${MACHINE_ARCH} == "mipsel") || \
	(${MACHINE_ARCH} == "m68k") || (${MACHINE_ARCH} == "vax")
.  else
PTHREAD_OPTS+=		require native
.  include "../../mk/pthread.buildlink3.mk"
.  endif

.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
NAME=	bsd

.elif ${OPSYS} == "Darwin"
NAME=	macintosh

.elif ${OPSYS} == "Linux"
NAME=	linux

.elif ${OPSYS} == "SunOS"

.  if !empty(CC_VERSION:M*gcc*)
NAME=	solaris
.  elif !empty(CC_VERSION:MSun)
NAME=	solaris_sunc
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
	cd ${WRKSRC}/config/bsd && \
	${SED} -e 's:@X11BASE@:${X11BASE}:g' define.h.in \
		> define.h
	cd ${WRKSRC} && ${MAKE} ${CONFIGURE_TARGET} name=${NAME}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
