# $NetBSD: Makefile,v 1.2 2025/08/12 16:25:41 hauke Exp $

PKGNAME=	asl-doc-${PKGVER}
COMMENT=	Portable macro cross assembler documentation

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-german-[0-9]*:../../print/tex-german
DEPENDS+=	texlive-collection-fontsrecommended-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended
DEPENDS+=	texlive-collection-latexrecommended-[0-9]*:../../meta-pkgs/texlive-collection-latexrecommended

DOCDIR=		share/doc/asl

INSTALLATION_DIRS+=	${DOCDIR}

.include "../../devel/asl/Makefile.common"

.include "../../mk/bsd.pkg.mk"
