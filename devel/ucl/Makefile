# $NetBSD: Makefile,v 1.13 2005/04/11 21:45:39 tv Exp $
#

DISTNAME=	ucl-1.02
PKGREVISION=	2
CATEGORIES=	devel archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/ucl/download/

MAINTAINER=	cjep@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/ucl/
COMMENT=	Portable lossless data compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-shared=yes

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=	F77=${FALSE}

INSTALLATION_DIRS=	bin

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ucl
	for i in simple.c lutil.h uclpack.c Makefile; do		\
	${INSTALL_DATA} ${WRKSRC}/examples/$$i ${PREFIX}/share/examples/ucl;\
		done;
	cd ${WRKSRC}/examples && libtool --mode=install ${INSTALL_PROGRAM} uclpack ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
