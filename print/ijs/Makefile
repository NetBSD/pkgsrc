# $NetBSD: Makefile,v 1.13 2006/02/05 23:10:37 joerg Exp $

DISTNAME=	ijs-0.34
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/ijs/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/ijs/
COMMENT=	Protocol library for raster page transmission

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILD_TARGET=		libijs.la
MAKE_ENV+=		XCFLAGS=${CFLAGS:M*:Q}
MAKE_ENV+=		IJS_VERSION_INFO="0:0"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ijs
	${INSTALL_DATA} ${WRKSRC}/ijs_spec.pdf ${PREFIX}/share/doc/ijs

.include "../../mk/bsd.pkg.mk"
