# $NetBSD: Makefile,v 1.17 2012/10/08 13:45:49 asau Exp $
#

DISTNAME=	xpdf-arabic-2003-feb-16
PKGNAME=	xpdf-arabic-20030216
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Arabic

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
