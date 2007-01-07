# $NetBSD: Makefile,v 1.7 2007/01/07 09:13:49 rillig Exp $
#

DISTNAME=	2vcard-0.5
CATEGORIES=	converters
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/apps/2vcard/
COMMENT=	Convert an addressbook to the popular VCARD file format

USE_TOOLS+=	perl:run
REPLACE_PERL=	src/2vcard

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/2vcard ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/2vcard.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/2vcard
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/html/2vcard

.include "../../mk/bsd.pkg.mk"
