# $NetBSD: Makefile,v 1.1.2.2 2002/06/23 18:41:50 jlam Exp $
#

DISTNAME=	2vcard-0.3
CATEGORIES=	converters
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www.netmeister.org/apps/2vcard/
COMMENT=	Convert an addressbook to the popular VCARD file format

USE_PERL5=	# defined
REPLACE_PERL=	src/2vcard

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/2vcard ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/2vcard.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/2vcard
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/2vcard
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/2vcard
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/2vcard
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/2vcard
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/html/2vcard

.include "../../mk/bsd.pkg.mk"
