# $NetBSD: Makefile,v 1.12 2004/07/28 11:06:43 wiz Exp $
#

DISTNAME=	xpdf-turkish
PKGNAME=	${DISTNAME}-20020410
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Turkish

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_PKGINSTALL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
DIST_SUBDIR=	${PKGNAME_NOREV}
NO_CONFIGURE=	yes
NO_BUILD=	yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

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
