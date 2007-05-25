# $NetBSD: Makefile,v 1.1.1.1 2007/05/25 11:54:17 jmmv Exp $

DISTNAME=	glossaries
PKGNAME=	tex-${DISTNAME}-1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/help/Catalogue/entries/glossaries.html
COMMENT=	Macros for creation of glossaries

DEPENDS+=	tex-xkeyval>=2.5f:../../print/tex-xkeyval

USE_DIRS+=	texmf-1.4
USE_TOOLS+=	perl:run

REPLACE_PERL=	scripts/makeglossaries

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && latex glossaries.ins

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/makeglossaries ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/doc/glossaries.pdf \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/glossaries
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossaries.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossary-hypernav.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossary-list.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossary-long.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries
	${INSTALL_DATA} ${WRKSRC}/glossary-super.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/glossaries

.include "../../mk/bsd.pkg.mk"
