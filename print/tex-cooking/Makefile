# $NetBSD: Makefile,v 1.1.1.1 2007/06/15 21:49:07 dmcmahill Exp $

DISTNAME=	cooking
PKGNAME=	tex-${DISTNAME}-0.9b
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/macros/latex/contrib/cooking/
COMMENT=	Typeset recipes

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_DIRS+=	texmf-1.0

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && latex cooking.ins
	cd ${WRKSRC} && latex cooking.dtx
	cd ${WRKSRC} && latex cooking.dtx
	cd ${WRKSRC} && latex cooking.dtx
	cd ${WRKSRC} && latex kraut.tex

do-install:
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/doc/latex/cooking
.for __tmp__ in README cooking.dvi kraut.tex kraut.dvi
	${INSTALL_DATA} ${WRKSRC}/${__tmp__} ${PKG_LOCALTEXMFPREFIX}/doc/latex/cooking
.endfor
	${INSTALL_DATA_DIR} ${PKG_LOCALTEXMFPREFIX}/tex/latex/cooking
	${INSTALL_DATA} ${WRKSRC}/cooking.sty \
		${PKG_LOCALTEXMFPREFIX}/tex/latex/cooking

.include "../../mk/bsd.pkg.mk"
