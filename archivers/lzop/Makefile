# $NetBSD: Makefile,v 1.9 2003/07/17 21:21:26 grant Exp $
#

DISTNAME=	lzop-1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzop/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzop/
COMMENT=	Fast file compressor similar to gzip, using the LZO library

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
