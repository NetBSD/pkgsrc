# $NetBSD: Makefile,v 1.4 2002/11/08 10:15:27 wiz Exp $
#

DISTNAME=	xpdf-latin2-2002-oct-22
PKGNAME=	xpdf-latin2-20021022
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Latin-2

DEPENDS+=	xpdf>=1.00:../../print/xpdf

USE_X11BASE=	yes

WRKSRC=		${WRKDIR}/xpdf-latin2
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${X11PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/xpdf/latin2
	${INSTALL_DATA} ${WRKSRC}/Latin2.unicodeMap \
		${X11PREFIX}/share/xpdf/latin2

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
