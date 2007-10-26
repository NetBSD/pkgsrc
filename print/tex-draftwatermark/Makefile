# $NetBSD: Makefile,v 1.1.1.1 2007/10/26 16:59:23 reed Exp $

DISTNAME=	draftwatermark
PKGNAME=	tex-${DISTNAME}-1.0
# version indicated in the PDF, last revised 2006/06/30
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/draftwatermark/
COMMENT=	Textual watermark package for LaTeX

DEPENDS+=	tex-everypage>=1.0:../../print/tex-everypage

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_DIRS+=	texmf-1.4

INSTALLATION_DIRS=	share/doc/tex-draftwatermark

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/latex draftwatermark.ins

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/draftwatermark
	${INSTALL_DATA} ${WRKSRC}/draftwatermark.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/draftwatermark/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tex-draftwatermark/
	${INSTALL_DATA} ${WRKSRC}/draftwatermark.pdf \
		${PREFIX}/share/doc/tex-draftwatermark/

.include "../../mk/bsd.pkg.mk"
