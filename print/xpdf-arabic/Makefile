# $NetBSD: Makefile,v 1.21 2021/04/24 11:09:48 wiz Exp $

DISTNAME=	xpdf-arabic-2011-aug-15
PKGNAME=	xpdf-arabic-20110815
CATEGORIES=	print
#MASTER_SITES=	https://dl.xpdfreader.com/xpdf-arabic.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Xpdf support files for Arabic
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02:../../print/xpdf

WRKSRC=		${WRKDIR}/xpdf-arabic
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/arabic

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/ISO-8859-6.unicodeMap ${WRKSRC}/add-to-xpdfrc \
		${DESTDIR}${PREFIX}/share/xpdf/arabic

.include "../../mk/bsd.pkg.mk"
