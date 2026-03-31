# $NetBSD: Makefile,v 1.27 2026/03/31 07:56:13 markd Exp $

DISTNAME=	pgf
PKGNAME=	tex-${DISTNAME}-3.1.11a
TEXLIVE_REV=	78101

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pgf
COMMENT=	Create PostScript and PDF graphics in TeX
LICENSE=	lppl-1.3c AND gnu-gpl-v2 AND gnu-fdl-v1.3

DEPENDS+=	tex-atveryend-[0-9]*:../../print/tex-atveryend
DEPENDS+=	tex-fp-[0-9]*:../../math/tex-fp
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

CHECK_INTERPRETER_SKIP=	share/texmf-dist/scripts/pgf/pgfrevisionfile.sh

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
