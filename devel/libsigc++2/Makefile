# $NetBSD: Makefile,v 1.2 2004/10/03 00:13:30 tv Exp $

DISTNAME=	libsigc++-2.0.3
PKGNAME=	libsigc++2-2.0.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		m4 make
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	sigc++-2.0.pc.in

CONFIGURE_ENV+=		ac_cv_prog_M4=${M4}

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

pre-install:
	${MKDIR} -p ${PREFIX}/include/sigc++-2.0/sigc++/adaptors/lambda/macros
	${MKDIR} -p ${PREFIX}/include/sigc++-2.0/sigc++/adaptors/macros
	${MKDIR} -p ${PREFIX}/include/sigc++-2.0/sigc++/functors/macros
	${MKDIR} -p ${PREFIX}/include/sigc++-2.0/sigc++/macros

.include "../../mk/bsd.pkg.mk"
