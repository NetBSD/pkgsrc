# $NetBSD: Makefile,v 1.3 2003/03/25 14:28:23 salo Exp $
#

DISTNAME=	xpdf-hebrew
PKGNAME=	${DISTNAME}-20030216
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Hebrew

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_PKGINSTALL=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/hebrew
	${INSTALL_DATA} ${WRKSRC}/ISO-8859-8.unicodeMap \
		${PREFIX}/share/xpdf/hebrew

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
