# $NetBSD: Makefile,v 1.6 2003/03/29 12:42:22 jmmv Exp $
#

DISTNAME=	xpdf-thai
PKGNAME=	${DISTNAME}-20020116
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Thai

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_PKGINSTALL=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/thai
	${INSTALL_DATA} ${WRKSRC}/TIS-620.unicodeMap \
		${PREFIX}/share/xpdf/thai
	${INSTALL_DATA} ${WRKSRC}/Thai.nameToUnicode \
		${PREFIX}/share/xpdf/thai

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
