# $NetBSD: Makefile,v 1.4 2001/06/11 06:34:17 jlam Exp $
#

DISTNAME=	lzop-1.00
CATEGORIES=	archivers
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/lzop.html
COMMENT=	Fast file compressor similar to gzip, using the LZO library

DEPENDS=	liblzo-*:../../archivers/liblzo

GNU_CONFIGURE=	YES
CPPFLAGS+=	-I${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
