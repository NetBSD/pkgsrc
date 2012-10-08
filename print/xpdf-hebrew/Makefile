# $NetBSD: Makefile,v 1.18 2012/10/08 13:45:49 asau Exp $
#

DISTNAME=	xpdf-hebrew-2003-feb-16
PKGNAME=	xpdf-hebrew-20030216
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Hebrew

DEPENDS+=	xpdf>=2.02:../../print/xpdf

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
