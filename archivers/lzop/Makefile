# $NetBSD: Makefile,v 1.12 2004/07/28 02:47:34 minskim Exp $
#

DISTNAME=	lzop-1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzop/
COMMENT=	Fast file compressor similar to gzip, using the LZO library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
