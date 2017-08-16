# $NetBSD: Makefile,v 1.18 2017/08/16 20:45:39 wiz Exp $
#

DISTNAME=	jpeg2ps-1.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.pdflib.com/fileadmin/pdflib/products/more/jpeg2ps/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.pdflib.com/download/free-software/jpeg2ps/
COMMENT=	Convert jpeg images to PostScript level 2 or 3
LICENSE=		jpeg2ps-license

RESTRICTED=		may not be sold or bundled with any commercial package
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jpeg2ps ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jpeg2ps.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
