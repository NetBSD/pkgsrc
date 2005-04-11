# $NetBSD: Makefile,v 1.14 2005/04/11 21:44:49 tv Exp $
#

DISTNAME=	lzop-1.01
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzop/
COMMENT=	Fast file compressor similar to gzip, using the LZO library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
