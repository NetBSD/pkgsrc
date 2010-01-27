# $NetBSD: Makefile,v 1.10 2010/01/27 16:06:46 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

.include "../../print/teTeX/module.mk"

post-extract:
	@cd ${WRKSRC}/type1 && ${UNZIP_CMD} -Laqo arrow.PC.zip

INSTALLATION_DIRS+=	${PKG_LOCALTEXMFPREFIX}/fonts/source/chemarrow \
	${PKG_LOCALTEXMFPREFIX}/tex/latex/chemarrow \
	${PKG_LOCALTEXMFPREFIX}/fonts/tfm/chemarrow \
	${PREFIX}/share/fonts/chemarrow

do-install:
	${INSTALL_DATA} ${WRKSRC}/arrow.mf 			\
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/source/chemarrow
	${INSTALL_DATA} ${WRKSRC}/arrow.tfm			\
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/fonts/tfm/chemarrow
	${INSTALL_DATA} ${WRKSRC}/chemarrow.sty			\
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/chemarrow
	cd ${WRKSRC}/type1/arrow\ PC && pax -rw . 		\
	    ${DESTDIR}${PREFIX}/share/fonts/chemarrow/

.include "../../mk/bsd.pkg.mk"
