# $NetBSD: Makefile,v 1.4 2003/12/31 14:58:50 cjep Exp $
#

DISTNAME=	ucl-1.02
CATEGORIES=	devel archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	cjep@NetBSD.org
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
