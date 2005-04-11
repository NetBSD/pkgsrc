# $NetBSD: Makefile,v 1.7 2005/04/11 21:45:27 tv Exp $

DISTNAME=	libsigc++-1.0.4
PKGREVISION=	2
PKGNAME=	${DISTNAME:S/libsigc++/libsigc++10/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sigc++
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/sigc++

.include "../../mk/bsd.pkg.mk"
