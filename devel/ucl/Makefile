# $NetBSD: Makefile,v 1.3 2003/07/17 21:34:07 grant Exp $
#

DISTNAME=	ucl-1.01
CATEGORIES=	devel archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/ucl/
COMMENT=	Portable lossless data compression library

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-shared=yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ucl
	for i in simple.c lutil.h uclpack.c Makefile; do		\
	${INSTALL_DATA} ${WRKSRC}/examples/$$i ${PREFIX}/share/examples/ucl;\
		done;

.include "../../mk/bsd.pkg.mk"
