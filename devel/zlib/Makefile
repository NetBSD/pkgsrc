# $NetBSD: Makefile,v 1.28 2004/11/04 14:17:55 adam Exp $

DISTNAME=	zlib-1.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		http://www.gzip.org/zlib/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gzip.org/zlib/
COMMENT=	General purpose data compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
INSTALLATION_DIRS=	include lib man/man3

.include "../../mk/bsd.pkg.mk"
