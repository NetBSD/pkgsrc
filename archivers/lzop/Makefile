# $NetBSD: Makefile,v 1.8 2003/06/02 01:21:46 jschauma Exp $
#

DISTNAME=	lzop-1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzop/download/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzop/
COMMENT=	Fast file compressor similar to gzip, using the LZO library

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
