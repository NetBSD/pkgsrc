# $NetBSD: Makefile,v 1.25 2003/06/06 08:58:42 jtb Exp $

DISTNAME=       	icon.v942src
PKGNAME=		icon-9.4.2
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.cs.arizona.edu/icon/index.htm
COMMENT=		The Icon programming language

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-i386 NetBSD-*-sparc NetBSD-*-powerpc \
			NetBSD-*-mipseb NetBSD-*-mipsel NetBSD-*-m68k NetBSD-*-vax

CONFIGURE_TARGET=	X-Configure
ALL_TARGET=		All

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
