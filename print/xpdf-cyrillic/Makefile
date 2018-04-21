# $NetBSD: Makefile,v 1.22 2018/04/21 13:38:06 wiz Exp $

DISTNAME=	xpdf-cyrillic-2011-aug-15
PKGNAME=	xpdf-cyrillic-20110815
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Cyrillic
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02:../../print/xpdf

WRKSRC=		${WRKDIR}/xpdf-cyrillic
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/cyrillic

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/Bulgarian.nameToUnicode \
	    ${WRKSRC}/KOI8-R.unicodeMap ${WRKSRC}/add-to-xpdfrc \
	    ${DESTDIR}${PREFIX}/share/xpdf/cyrillic

.include "../../mk/bsd.pkg.mk"
