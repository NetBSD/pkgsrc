# $NetBSD: Makefile,v 1.2 2002/08/06 14:50:22 wiz Exp $
#

DISTNAME=	xpdf-cyrillic
PKGNAME=	${DISTNAME}-20020521
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Cyrillic

DEPENDS+=	xpdf>=1.00:../../print/xpdf

USE_X11BASE=	yes

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${X11PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/xpdf/cyrillic
	${INSTALL_DATA} ${WRKSRC}/KOI8-R.unicodeMap \
		${X11PREFIX}/share/xpdf/cyrillic

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${X11PREFIX}/etc/xpdfrc

.include "../../mk/bsd.pkg.mk"
