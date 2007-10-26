# $NetBSD: Makefile,v 1.1.1.1 2007/10/26 16:57:51 reed Exp $

DISTNAME=	everypage
PKGNAME=	tex-${DISTNAME}-1.0
# version indicated in the PDF, last revised 2006/06/30
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/everypage/
COMMENT=	LaTeX package for hooks to run on every page

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_DIRS+=	texmf-1.4

INSTALLATION_DIRS=	share/doc/tex-everypage

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/latex everypage.ins

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/everypage
	${INSTALL_DATA} ${WRKSRC}/everypage.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/everypage/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tex-everypage/
	${INSTALL_DATA} ${WRKSRC}/everypage.pdf \
		${PREFIX}/share/doc/tex-everypage/

.include "../../mk/bsd.pkg.mk"
