# $NetBSD: Makefile,v 1.1 2025/05/13 09:28:33 markd Exp $

DISTNAME=	gentium-otf
PKGNAME=	tex-${DISTNAME}-0.02
TEXLIVE_REV=	74545

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/gentium-otf
COMMENT=	Support for the TrueType font GentiumPlus
LICENSE=	lppl-1.3c

DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-unicode-math-[0-9]*:../../math/tex-unicode-math
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
