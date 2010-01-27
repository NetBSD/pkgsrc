# $NetBSD: Makefile,v 1.3 2010/01/27 16:10:09 joerg Exp $

DISTNAME=	draftwatermark
PKGNAME=	tex-${DISTNAME}-1.0
# version indicated in the PDF, last revised 2006/06/30
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.ctan.org/tex-archive/macros/latex/contrib/draftwatermark/
COMMENT=	Textual watermark package for LaTeX

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	tex-everypage>=1.0:../../print/tex-everypage

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/doc/tex-draftwatermark \
			${PKG_LOCALTEXMFPREFIX}/tex/latex/draftwatermark

.include "../../print/teTeX/module.mk"

do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/latex draftwatermark.ins

do-install:
	${INSTALL_DATA} ${WRKSRC}/draftwatermark.sty \
	    ${DESTDIR}${PKG_LOCALTEXMFPREFIX}/tex/latex/draftwatermark/
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${DESTDIR}${PREFIX}/share/doc/tex-draftwatermark/
	${INSTALL_DATA} ${WRKSRC}/draftwatermark.pdf \
	    ${DESTDIR}${PREFIX}/share/doc/tex-draftwatermark/

.include "../../mk/bsd.pkg.mk"
