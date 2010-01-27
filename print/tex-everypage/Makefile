# $NetBSD: Makefile,v 1.3 2010/01/27 16:12:38 joerg Exp $

DISTNAME=	everypage
PKGNAME=	tex-${DISTNAME}-1.0
# version indicated in the PDF, last revised 2006/06/30
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/everypage/
COMMENT=	LaTeX package for hooks to run on every page

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/doc/tex-everypage \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/everypage

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/latex everypage.ins

do-install:
	${INSTALL_DATA} ${WRKSRC}/everypage.sty \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/everypage/
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${DESTDIR}${PREFIX}/share/doc/tex-everypage/
	${INSTALL_DATA} ${WRKSRC}/everypage.pdf \
	    ${DESTDIR}${PREFIX}/share/doc/tex-everypage/

.include "../../mk/bsd.pkg.mk"
