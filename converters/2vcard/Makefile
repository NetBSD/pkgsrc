# $NetBSD: Makefile,v 1.18 2018/08/22 09:43:05 wiz Exp $
#

DISTNAME=	2vcard-0.5
PKGREVISION=	7
CATEGORIES=	converters
MASTER_SITES=	http://www.netmeister.org/apps/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netmeister.org/apps/2vcard/
COMMENT=	Convert an addressbook to the popular VCARD file format
LICENSE=	modified-bsd

USE_TOOLS+=	perl:run
REPLACE_PERL=	src/2vcard

NO_BUILD=	yes
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/2vcard ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/2vcard.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/doc/html/* \
		${DESTDIR}${PREFIX}/share/doc/2vcard

.include "../../mk/bsd.pkg.mk"
