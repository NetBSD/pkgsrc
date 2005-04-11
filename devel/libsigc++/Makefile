# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:27 tv Exp $

DISTNAME=	libsigc++-1.2.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		m4 make
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	sigc++-1.2.pc.in

CONFIGURE_ENV+=		ac_cv_prog_M4=${M4}

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
