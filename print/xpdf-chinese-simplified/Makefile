# $NetBSD: Makefile,v 1.11 2003/08/30 22:51:31 jlam Exp $
#

DISTNAME=	xpdf-chinese-simplified
PKGNAME=	${DISTNAME}-20020617
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Chinese (Simplified)

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_PKGINSTALL=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_CONFIGURE=	yes
NO_BUILD=	yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA} ${WRKSRC}/Adobe-GB1.cidToUnicode \
		${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA} ${WRKSRC}/EUC-CN.unicodeMap \
		${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA} ${WRKSRC}/GBK.unicodeMap \
		${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA} ${WRKSRC}/ISO-2022-CN.unicodeMap \
		${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/chinese-simplified/CMap
	${INSTALL_DATA} ${WRKSRC}/CMap/* ${PREFIX}/share/xpdf/chinese-simplified/CMap

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
