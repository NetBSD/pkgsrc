# $NetBSD: Makefile,v 1.3 2010/01/27 15:55:58 joerg Exp $

DISTNAME=	abc
PKGNAME=	tex-${DISTNAME}-1.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://tug.ctan.org/tex-archive/macros/latex/contrib/
COMMENT=	Support ABC music notation in LaTeX

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	abcm2ps-[0-9]*:../../print/abcm2ps
DEPENDS+=	ps2eps-[0-9]*:../../graphics/ps2eps

.include "../../print/teTeX/module.mk"

INSTALLATION_DIRS+=	${PKG_LOCALTEXMFPREFIX}/doc/latex/abc \
			${PKG_LOCALTEXMFPREFIX:Q}/tex/latex/abc

do-build:
	cd ${WRKSRC} && latex abc.ins

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/abc.pdf \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/abc
	${INSTALL_DATA} ${WRKSRC}/example.tex \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/doc/latex/abc
	${INSTALL_DATA} ${WRKSRC}/abc.sty \
		${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/abc

.include "../../mk/bsd.pkg.mk"
