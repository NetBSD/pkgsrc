# $NetBSD: Makefile,v 1.22 2004/01/12 21:19:50 adam Exp $

DISTNAME=	zlib-1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		http://www.gzip.org/zlib/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gzip.org/zlib/
COMMENT=	General purpose data compression library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		# defined
USE_LIBTOOL=		# defined
HAS_CONFIGURE=		# defined
INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.pkg.mk"
