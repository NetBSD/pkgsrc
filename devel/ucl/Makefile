# $NetBSD: Makefile,v 1.7 2004/04/21 04:04:59 snj Exp $
#

DISTNAME=	ucl-1.02
CATEGORIES=	devel archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/ucl/
COMMENT=	Portable lossless data compression library

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-shared=yes

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=	F77=${FALSE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ucl
	for i in simple.c lutil.h uclpack.c Makefile; do		\
	${INSTALL_DATA} ${WRKSRC}/examples/$$i ${PREFIX}/share/examples/ucl;\
		done;

.include "../../mk/bsd.pkg.mk"
