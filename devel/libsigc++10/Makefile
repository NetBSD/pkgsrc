# $NetBSD: Makefile,v 1.4 2004/02/05 08:00:08 grant Exp $

DISTNAME=	libsigc++-1.0.4
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/libsigc++/libsigc++10/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsigc/}

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://libsigc.sourceforge.net/
COMMENT=	Type-safe callback system for C++ programs

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--disable-threads
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sigc++
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/sigc++

.include "../../mk/bsd.pkg.mk"
