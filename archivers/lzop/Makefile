# $NetBSD: Makefile,v 1.3 2001/02/16 13:15:33 wiz Exp $
#

DISTNAME=	lzop-1.00
CATEGORIES=	archivers
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/lzop.html
COMMENT=	Fast file compressor similar to gzip, using the LZO library

DEPENDS=	liblzo-*:../../archivers/liblzo

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
