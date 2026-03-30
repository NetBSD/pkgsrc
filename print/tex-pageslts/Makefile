# $NetBSD: Makefile,v 1.8 2026/03/30 19:57:25 markd Exp $

DISTNAME=	pageslts
PKGNAME=	tex-${DISTNAME}-2.0g
TEXLIVE_REV=	76054

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pageslts
COMMENT=	Variants of last page labels
LICENSE=	lppl-1.3c

DEPENDS+=	tex-alphalph-[0-9]*:../../print/tex-alphalph
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-letltxmacro-[0-9]*:../../print/tex-letltxmacro
DEPENDS+=	tex-rerunfilecheck-[0-9]*:../../print/tex-rerunfilecheck
DEPENDS+=	tex-undolabl-[0-9]*:../../print/tex-undolabl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
