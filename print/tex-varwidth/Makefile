# $NetBSD: Makefile,v 1.1 2014/10/01 19:58:19 joerg Exp $

DISTNAME=	varwidth
PKGNAME=	tex-${DISTNAME}-0.92
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	A variable-width minipage

INSTALLATION_DIRS=	share/texmf-dist/doc/latex/varwidth \
			share/texmf-dist/tex/latex/varwidth

do-install:
	${INSTALL_DATA} ${WRKSRC}/varwidth/varwidth-doc.pdf \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/varwidth/varwidth.pdf
	${INSTALL_DATA} ${WRKSRC}/varwidth/varwidth.sty \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/varwidth

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
