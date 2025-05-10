# $NetBSD: Makefile,v 1.7 2025/05/10 22:41:28 markd Exp $

DISTNAME=	pageslts
PKGNAME=	tex-${DISTNAME}-2.0d
TEXLIVE_REV=	73400

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide labels for the last page in each page numbering group
LICENSE=	lppl-1.3c

DEPENDS+=	tex-alphalph-[0-9]*:../../print/tex-alphalph
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-letltxmacro-[0-9]*:../../print/tex-letltxmacro
DEPENDS+=	tex-rerunfilecheck-[0-9]*:../../print/tex-rerunfilecheck
DEPENDS+=	tex-undolabl-[0-9]*:../../print/tex-undolabl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
