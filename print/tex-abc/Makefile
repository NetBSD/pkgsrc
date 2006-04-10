# $NetBSD: Makefile,v 1.1.1.1 2006/04/10 20:16:06 minskim Exp $

DISTNAME=	abc
PKGNAME=	tex-${DISTNAME}-1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/macros/latex/contrib/
COMMENT=	Support ABC music notation in LaTeX

DEPENDS+=	abcm2ps-[0-9]*:../../print/abcm2ps
DEPENDS+=	ps2eps-[0-9]*:../../graphics/ps2eps

USE_DIRS+=	texmf-dirs-1.0

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && latex abc.ins

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/abc
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/abc.pdf \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/abc
	${INSTALL_DATA} ${WRKSRC}/example.tex \
		${PKG_LOCALTEXMFPREFIX}/doc/latex/abc
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX:Q}/tex/latex/abc
	${INSTALL_DATA} ${WRKSRC}/abc.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/abc

.include "../../mk/bsd.pkg.mk"
