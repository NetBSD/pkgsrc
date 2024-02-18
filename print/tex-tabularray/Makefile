# $NetBSD: Makefile,v 1.4 2024/02/18 10:46:53 markd Exp $

DISTNAME=	tabularray
PKGNAME=	tex-${DISTNAME}-2024A
TEXLIVE_REV=	69926

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tabularray
COMMENT=	Typeset tabulars and arrays with LaTeX3
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-ninecolors-[0-9]*:../../print/tex-ninecolors

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
