# $NetBSD: Makefile,v 1.23 2023/07/03 13:11:48 wiz Exp $

DISTNAME=	xpdf-hebrew-2011-aug-15
PKGNAME=	xpdf-hebrew-20110815
CATEGORIES=	print
#MASTER_SITES=	https://dl.xpdfreader.com/xpdf-hebrew.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Xpdf support files for Hebrew
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02<4:../../print/xpdf

WRKSRC=		${WRKDIR}/xpdf-hebrew
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/hebrew

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/ISO-8859-8.unicodeMap ${WRKSRC}/add-to-xpdfrc \
		${DESTDIR}${PREFIX}/share/xpdf/hebrew

.include "../../mk/bsd.pkg.mk"
