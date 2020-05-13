# $NetBSD: Makefile,v 1.21 2020/05/13 19:58:32 fcambus Exp $
#

DISTNAME=	2vcard-0.6
CATEGORIES=	converters
MASTER_SITES=	https://www.netmeister.org/apps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.netmeister.org/apps/2vcard/
COMMENT=	Convert an addressbook to the popular VCARD file format
LICENSE=	modified-bsd

USE_TOOLS+=	perl:run

NO_BUILD=	yes
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/2vcard ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/2vcard.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/html/* \
		${DESTDIR}${PREFIX}/share/doc/2vcard

.include "../../mk/bsd.pkg.mk"
