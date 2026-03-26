# $NetBSD: Makefile,v 1.13 2026/03/26 19:27:34 markd Exp $

DISTNAME=	unicode-math
PKGNAME=	tex-${DISTNAME}-0.8r.78251
TEXLIVE_REV=	78251

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/unicode-math
COMMENT=	Unicode mathematics support for XeTeX and LuaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-filehook-[0-9]*:../../print/tex-filehook
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-lm-math-[0-9]*:../../fonts/tex-lm-math
DEPENDS+=	tex-lualatex-math-[0-9]*:../../math/tex-lualatex-math

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
