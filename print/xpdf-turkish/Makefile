# $NetBSD: Makefile,v 1.4 2003/03/25 14:07:04 salo Exp $
#

DISTNAME=	xpdf-turkish
PKGNAME=	${DISTNAME}-20020410
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Turkish

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_X11=	yes
USE_PKGINSTALL=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/turkish
	${INSTALL_DATA} ${WRKSRC}/ISO-8859-9.unicodeMap \
		${PREFIX}/share/xpdf/turkish

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
