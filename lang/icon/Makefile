# $NetBSD: Makefile,v 1.30 2004/04/28 05:06:28 snj Exp $

DISTNAME=       	icon.v942src
PKGNAME=		icon-9.4.2
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/icon/index.htm
COMMENT=		The Icon programming language

USE_BUILDLINK3=		YES
USE_X11=		YES
CONFIGURE_TARGET=	X-Configure
ALL_TARGET=		All
TEST_TARGET=		Test

.if (${MACHINE_ARCH} == "alpha") || (${MACHINE_ARCH} == "i386") || \
	(${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "powerpc") || \
	(${MACHINE_ARCH} == "mipseb") || (${MACHINE_ARCH} == "mipsel") || \
	(${MACHINE_ARCH} == "m68k") || (${MACHINE_ARCH} == "vax")
.else
PTHREAD_OPTS+=		require native
.include "../../mk/pthread.buildlink3.mk"
.endif

pre-build:
	${MKDIR} ${WRKSRC}/lib/icon

do-configure:
	cd ${WRKSRC}/config/netbsd; \
	${SED} -e 's:@X11BASE@:${X11BASE}:g' define.h.in \
		> define.h
	cd ${WRKSRC}; ${MAKE} ${CONFIGURE_TARGET} name=netbsd

do-install:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} dest=${PREFIX} Install

.include "../../mk/bsd.pkg.mk"
