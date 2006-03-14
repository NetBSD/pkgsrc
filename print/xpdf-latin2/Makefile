# $NetBSD: Makefile,v 1.19 2006/03/14 01:14:33 jlam Exp $
#

DISTNAME=	xpdf-latin2-2002-oct-22
PKGNAME=	xpdf-latin2-20021022
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Latin-2

DEPENDS+=	xpdf>=2.02:../../print/xpdf


WRKSRC=		${WRKDIR}/xpdf-latin2
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/latin2
	${INSTALL_DATA} ${WRKSRC}/Latin2.unicodeMap \
		${PREFIX}/share/xpdf/latin2

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
