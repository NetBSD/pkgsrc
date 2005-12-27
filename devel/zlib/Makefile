# $NetBSD: Makefile,v 1.32 2005/12/27 17:27:58 reed Exp $

DISTNAME=	zlib-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		http://www.gzip.org/zlib/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gzip.org/zlib/
COMMENT=	General purpose data compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
INSTALLATION_DIRS=	include lib ${PKGMANDIR}/man3

.include "../../mk/bsd.pkg.mk"
