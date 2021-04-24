# $NetBSD: Makefile,v 1.24 2021/04/24 11:09:49 wiz Exp $

DISTNAME=	xpdf-thai-2011-aug-15
PKGNAME=	xpdf-thai-20110815
CATEGORIES=	print
#MASTER_SITES=	https://dl.xpdfreader.com/xpdf-thai.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Xpdf support files for Thai
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02:../../print/xpdf

WRKSRC=		${WRKDIR}/xpdf-thai
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/thai

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/TIS-620.unicodeMap \
	    ${WRKSRC}/Thai.nameToUnicode ${WRKSRC}/add-to-xpdfrc \
	    ${DESTDIR}${PREFIX}/share/xpdf/thai

.include "../../mk/bsd.pkg.mk"
