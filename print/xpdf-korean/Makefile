# $NetBSD: Makefile,v 1.12 2004/01/20 12:24:30 agc Exp $
#

DISTNAME=	xpdf-korean-2004-jan-16
PKGNAME=	xpdf-korean-20040116
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Korean

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_PKGINSTALL=	yes

WRKSRC=		${WRKDIR}/xpdf-korean
NO_CONFIGURE=	yes
NO_BUILD=	yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/korean
	${INSTALL_DATA} ${WRKSRC}/Adobe-Korea1.cidToUnicode \
		${PREFIX}/share/xpdf/korean
	${INSTALL_DATA} ${WRKSRC}/ISO-2022-KR.unicodeMap \
		${PREFIX}/share/xpdf/korean
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/korean/CMap
	${INSTALL_DATA} ${WRKSRC}/CMap/* ${PREFIX}/share/xpdf/korean/CMap

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
