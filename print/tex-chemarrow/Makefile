# $NetBSD: Makefile,v 1.1 2005/05/16 22:30:24 jschauma Exp $
#

DISTNAME=	chemarrow
PKGNAME=	tex-${DISTNAME}-0.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/help/Catalogue/entries/chemarrow.html
COMMENT=	New arrow heads for chemical reaction schemes

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX-bin

NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	@(cd ${WRKSRC}/type1 && ${EXTRACT_CMD.zip} arrow.PC.zip)

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/source/chemarrow
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/tex/latex/chemarrow
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/tfm/chemarrow
	${INSTALL_DATA_DIR} ${PREFIX}/share/fonts/chemarrow
	${INSTALL_DATA} ${WRKSRC}/arrow.mf 			\
		${PREFIX}/share/texmf/fonts/source/chemarrow
	${INSTALL_DATA} ${WRKSRC}/arrow.tfm			\
		${PREFIX}/share/texmf/fonts/tfm/chemarrow
	${INSTALL_DATA} ${WRKSRC}/chemarrow.sty			\
		${PREFIX}/share/texmf/tex/latex/chemarrow
	cd ${WRKSRC}/type1/arrow\ PC && ${PAX} -rw . 		\
		${PREFIX}/share/fonts/chemarrow/
	${LOCALBASE}/bin/texconfig rehash
	${LOCALBASE}/bin/mktexlsr

.include "../../mk/bsd.pkg.mk"
