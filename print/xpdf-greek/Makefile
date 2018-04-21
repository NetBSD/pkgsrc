# $NetBSD: Makefile,v 1.22 2018/04/21 13:38:06 wiz Exp $

DISTNAME=	xpdf-greek-2011-aug-15
PKGNAME=	xpdf-greek-20110815
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Greek
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02:../../print/xpdf

WRKSRC=		${WRKDIR}/xpdf-greek
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/greek

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/Greek.nameToUnicode \
	    ${WRKSRC}/ISO-8859-7.unicodeMap ${WRKSRC}/add-to-xpdfrc \
	    ${DESTDIR}${PREFIX}/share/xpdf/greek

.include "../../mk/bsd.pkg.mk"
