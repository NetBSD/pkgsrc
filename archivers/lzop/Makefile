# $NetBSD: Makefile,v 1.1.1.1 1999/08/16 15:39:22 rh Exp $
#

DISTNAME=	lzop-1.00
CATEGORIES=	archivers
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/lzop.html

DEPENDS=	liblzo-1.04:../../archivers/liblzo

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
