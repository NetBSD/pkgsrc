# $NetBSD: Makefile,v 1.25 2019/08/12 11:40:53 markd Exp $

DISTNAME=	oberdiek
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	51770

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/oberdiek
COMMENT=	Bundle of packages submitted by Heiko Oberdiek
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

USE_TOOLS+=	perl:run

REPLACE_PERL=	bin/pdfatfi

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/scripts/oberdiek/pdfatfi.pl ${WRKSRC}/bin/pdfatfi

.include "../../mk/bsd.pkg.mk"
