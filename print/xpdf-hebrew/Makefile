# $NetBSD: Makefile,v 1.1.1.1 2002/11/08 10:08:59 wiz Exp $
#

DISTNAME=	xpdf-hebrew-2002-oct-22
PKGNAME=	xpdf-hebrew-20021022
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Hebrew

DEPENDS+=	xpdf>=1.00:../../print/xpdf

USE_X11BASE=	yes

WRKSRC=		${WRKDIR}/xpdf-hebrew
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${X11PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/xpdf/hebrew
	${INSTALL_DATA} ${WRKSRC}/ISO-8859-8.unicodeMap \
		${X11PREFIX}/share/xpdf/hebrew

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
