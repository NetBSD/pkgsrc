# $NetBSD: Makefile,v 1.12 2008/03/04 15:39:10 jlam Exp $
#

DISTNAME=	jpeg2ps-1.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.pdflib.com/products/more/jpeg2ps/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.pdflib.com/products/more/jpeg2ps.html
COMMENT=	Convert jpeg images to PostScript level 2 or 3

RESTRICTED=		may not be sold
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jpeg2ps.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
