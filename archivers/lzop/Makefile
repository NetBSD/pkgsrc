# $NetBSD: Makefile,v 1.7 2003/05/08 09:45:47 wiz Exp $
#

DISTNAME=	lzop-1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzop/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzop/
COMMENT=	Fast file compressor similar to gzip, using the LZO library

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
