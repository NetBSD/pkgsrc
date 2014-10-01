# $NetBSD: Makefile,v 1.1 2014/10/01 19:58:54 joerg Exp $

DISTNAME=	tabu
PKGNAME=	tex-${DISTNAME}-2.8
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/latex/contrib/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Flexible LaTeX tabulars

INSTALLATION_DIRS=	share/texmf-dist/doc/latex/tabu \
			share/texmf-dist/tex/latex/tabu

DEPENDS+=	tex-varwidth-[0-9]*:../../print/tex-varwidth

do-configure:
	cd ${WRKSRC}/tabu && ${PREFIX}/bin/latex tabu.ins

do-install:
	${INSTALL_DATA} ${WRKSRC}/tabu/tabu.pdf \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/doc/latex/tabu
	${INSTALL_DATA} ${WRKSRC}/tabu/tabu.sty \
	    ${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/tabu

.include "../../print/kpathsea/texmf.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
