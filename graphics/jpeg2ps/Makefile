# $NetBSD: Makefile,v 1.4 2004/04/25 11:44:59 dillo Exp $
#

DISTNAME=	jpeg2ps-1.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.pdflib.com/products/more/jpeg2ps/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.pdflib.com/products/more/jpeg2ps/
COMMENT=	Convert jpeg images to PostScript level 2 or 3

USE_BUILDLINK3=	YES

RESTRICTED=	may not be sold
NO_SRC_ON_CD=	${RESTRICTED}
NO_BIN_ON_CD=	${RESTRICTED}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${LOCALBASE}/bin
	${INSTALL_MAN} ${WRKSRC}/jpeg2ps.1 ${LOCALBASE}/man/man1

.include "../../mk/bsd.pkg.mk"
