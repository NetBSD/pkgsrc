# $NetBSD: Makefile,v 1.1.1.1 2006/06/11 06:13:35 minskim Exp $

DISTNAME=	igo
PKGNAME=	tex-${DISTNAME}-0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=fonts/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/fonts/igo/
COMMENT=	Fonts and macro to typeset Go diagrams

USE_DIRS+=	texmf-1.2

.include "../../print/teTeX/module.mk"

do-configure:
	${GREP} "^maketfm" ${WRKSRC}/fonts/makefonts.bat | \
	${SED} -e 's/maketfm/mktextfm/g' > ${WRKSRC}/fonts/makefonts.sh

do-build:
	cd ${WRKSRC}/fonts && ${SH} makefonts.sh

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/igo
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/igo.pdf ${WRKSRC}/igo.tex \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/igo
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/igo
	${INSTALL_DATA} ${WRKSRC}/igo.sty ${WRKSRC}/repeat.tex \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/igo
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/source/igo
	${INSTALL_DATA} ${WRKSRC}/fonts/*.mf \
		${PKG_LOCALTEXMFPREFIX}/fonts/source/igo
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/fonts/tfm/igo
	${INSTALL_DATA} ${WRKSRC}/fonts/*.tfm \
		${PKG_LOCALTEXMFPREFIX}/fonts/tfm/igo

.include "../../mk/bsd.pkg.mk"
