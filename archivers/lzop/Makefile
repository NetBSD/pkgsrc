# $NetBSD: Makefile,v 1.5 2001/07/16 09:58:10 jlam Exp $
#

DISTNAME=	lzop-1.00
CATEGORIES=	archivers
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/lzop.html
COMMENT=	Fast file compressor similar to gzip, using the LZO library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../archivers/liblzo/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
