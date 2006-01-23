# $NetBSD: Makefile,v 1.4 2006/01/23 18:37:18 jlam Exp $
#

DISTNAME=	chemarrow
PKGNAME=	tex-${DISTNAME}-0.1
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/help/Catalogue/entries/chemarrow.html
COMMENT=	New arrow heads for chemical reaction schemes

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../print/teTeX/module.mk"

post-extract:
	@cd ${WRKSRC}/type1 && ${UNZIP_CMD} -Laqo arrow.PC.zip

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/source/chemarrow
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/chemarrow
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/chemarrow
	${INSTALL_DATA_DIR} ${PREFIX}/share/fonts/chemarrow
	${INSTALL_DATA} ${WRKSRC}/arrow.mf 			\
		${PKG_LOCALTEXMFPREFIX}/fonts/source/chemarrow
	${INSTALL_DATA} ${WRKSRC}/arrow.tfm			\
		${PKG_LOCALTEXMFPREFIX}/fonts/tfm/chemarrow
	${INSTALL_DATA} ${WRKSRC}/chemarrow.sty			\
		${PKG_LOCALTEXMFPREFIX}/tex/latex/chemarrow
	cd ${WRKSRC}/type1/arrow\ PC && ${PAX} -rw . 		\
		${PREFIX}/share/fonts/chemarrow/

.include "../../mk/bsd.pkg.mk"
