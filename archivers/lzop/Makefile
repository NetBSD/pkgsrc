# $NetBSD: Makefile,v 1.2 1999/12/22 19:44:49 rh Exp $
#

DISTNAME=	lzop-1.00
CATEGORIES=	archivers
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wildsau.idv.uni-linz.ac.at/mfx/lzop.html

DEPENDS=	liblzo-*:../../archivers/liblzo

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
