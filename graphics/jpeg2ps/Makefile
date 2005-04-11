# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:05 tv Exp $
#

DISTNAME=	jpeg2ps-1.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.pdflib.com/products/more/jpeg2ps/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.pdflib.com/products/more/jpeg2ps/
COMMENT=	Convert jpeg images to PostScript level 2 or 3


RESTRICTED=	may not be sold
NO_SRC_ON_CD=	${RESTRICTED}
NO_BIN_ON_CD=	${RESTRICTED}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${LOCALBASE}/bin
	${INSTALL_MAN} ${WRKSRC}/jpeg2ps.1 ${LOCALBASE}/man/man1

.include "../../mk/bsd.pkg.mk"
