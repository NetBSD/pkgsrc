# $NetBSD: Makefile,v 1.27 2004/10/03 00:13:34 tv Exp $

DISTNAME=	zlib-1.2.1
PKGREVISION=	3
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
USE_LIBTOOL=		# defined
HAS_CONFIGURE=		# defined
INSTALLATION_DIRS=	include lib man/man3

.include "../../mk/bsd.pkg.mk"
