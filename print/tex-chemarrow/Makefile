# $NetBSD: Makefile,v 1.2 2005/11/08 21:45:01 tonio Exp $
#

DISTNAME=	chemarrow
PKGNAME=	tex-${DISTNAME}-0.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/help/Catalogue/entries/chemarrow.html
COMMENT=	New arrow heads for chemical reaction schemes

NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	@(cd ${WRKSRC}/type1 && ${EXTRACT_CMD.zip} arrow.PC.zip)

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
	${LOCALBASE}/bin/texconfig rehash
	${LOCALBASE}/bin/mktexlsr

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
