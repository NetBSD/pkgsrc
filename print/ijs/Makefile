# $NetBSD: Makefile,v 1.1.1.1 2002/09/11 18:37:09 jlam Exp $

DISTNAME=	ijs-0.34
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/ijs/download/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.linuxprinting.org/ijs/
COMMENT=	protocol library for raster page transmission

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined

ALL_TARGET=		libijs.la
MAKE_ENV+=		XCFLAGS="${CFLAGS}"
MAKE_ENV+=		IJS_VERSION_INFO="0:0"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ijs
	${INSTALL_DATA} ${WRKSRC}/ijs_spec.pdf ${PREFIX}/share/doc/ijs

.include "../../mk/bsd.pkg.mk"
