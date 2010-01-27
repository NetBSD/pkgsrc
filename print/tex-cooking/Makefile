# $NetBSD: Makefile,v 1.3 2010/01/27 16:08:19 joerg Exp $

DISTNAME=	cooking
PKGNAME=	tex-${DISTNAME}-0.9b
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/macros/latex/contrib/cooking/
COMMENT=	Typeset recipes

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && latex cooking.ins
	cd ${WRKSRC} && latex cooking.dtx
	cd ${WRKSRC} && latex cooking.dtx
	cd ${WRKSRC} && latex cooking.dtx
	cd ${WRKSRC} && latex kraut.tex

INSTALLATION_DIRS=	${PKG_LOCALTEXMFPREFIX}/doc/latex/cooking \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/cooking

do-install:
.for __tmp__ in README cooking.dvi kraut.tex kraut.dvi
	${INSTALL_DATA} ${WRKSRC}/${__tmp__} ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/cooking
.endfor
	${INSTALL_DATA} ${WRKSRC}/cooking.sty \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/cooking

.include "../../mk/bsd.pkg.mk"
