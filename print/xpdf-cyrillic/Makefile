# $NetBSD: Makefile,v 1.12 2004/01/20 12:24:29 agc Exp $
#

DISTNAME=	xpdf-cyrillic-2003-jun-28
PKGNAME=	xpdf-cyrillic-20030628
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Cyrillic

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_PKGINSTALL=	yes

WRKSRC=		${WRKDIR}/xpdf-cyrillic
NO_CONFIGURE=	yes
NO_BUILD=	yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/cyrillic
	${INSTALL_DATA} ${WRKSRC}/Bulgarian.nameToUnicode \
		${PREFIX}/share/xpdf/cyrillic
	${INSTALL_DATA} ${WRKSRC}/KOI8-R.unicodeMap \
		${PREFIX}/share/xpdf/cyrillic

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
