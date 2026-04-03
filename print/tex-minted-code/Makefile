# $NetBSD: Makefile,v 1.1 2026/04/03 01:54:05 markd Exp $

DISTNAME=	minted-code
PKGNAME=	tex-${DISTNAME}-0.01
TEXLIVE_REV=	76529

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/minted-code
COMMENT=	Predefined environments for typesetting LaTeX code with minted
LICENSE=	lppl-1.3c

DEPENDS+=	tex-minted-[0-9]*:../../print/tex-minted
DEPENDS+=	tex-tcolorbox-[0-9]*:../../print/tex-tcolorbox

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
