# $NetBSD: Makefile,v 1.15 2004/02/02 13:02:49 jlam Exp $

DISTNAME=	libsigc++-1.2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		m4 make
USE_LANGUAGES=		c c++

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/sigc++-1.2.pc.in

CONFIGURE_ENV+=		ac_cv_prog_M4=${M4}

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

.include "../../mk/bsd.pkg.mk"
