# $NetBSD: Makefile,v 1.8 2008/05/26 02:13:23 joerg Exp $
#

DISTNAME=	chemarrow
PKGNAME=	tex-${DISTNAME}-0.1
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/help/Catalogue/entries/chemarrow.html
COMMENT=	New arrow heads for chemical reaction schemes

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_DIRS+=	texmf-1.0

USE_TOOLS+=	pax

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
	cd ${WRKSRC}/type1/arrow\ PC && pax -rw . 		\
		${PREFIX}/share/fonts/chemarrow/

.include "../../mk/bsd.pkg.mk"
