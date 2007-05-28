# $NetBSD: Makefile,v 1.1.1.1 2007/05/28 14:07:16 jmmv Exp $

DISTNAME=	algorithm2e
PKGNAME=	tex-${DISTNAME}-3.9
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.ctan.org/tex-archive/help/Catalogue/entries/algorithm2e.html
COMMENT=	Environment for writing algorithms

NO_BUILD=	yes
USE_DIRS+=	texmf-1.4

.include "../../print/teTeX/module.mk"

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/algorithm2e
	${INSTALL_DATA} ${WRKSRC}/algorithm2e.pdf \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/algorithm2e
	${INSTALL_DATA} ${WRKSRC}/algorithm2e_ex*.tex \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/algorithm2e
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/algorithm2e
	${INSTALL_DATA} ${WRKSRC}/algorithm2e.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/algorithm2e

.include "../../mk/bsd.pkg.mk"
