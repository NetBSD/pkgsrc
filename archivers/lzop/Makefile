# $NetBSD: Makefile,v 1.6 2002/08/25 21:49:15 jlam Exp $
#

DISTNAME=	lzop-1.00
CATEGORIES=	archivers
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/lzop.html
COMMENT=	Fast file compressor similar to gzip, using the LZO library

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
