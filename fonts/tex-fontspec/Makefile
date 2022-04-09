# $NetBSD: Makefile,v 1.21 2022/04/09 21:09:00 markd Exp $

DISTNAME=	fontspec
PKGNAME=	tex-${DISTNAME}-2.8a
TEXLIVE_REV=	61617

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fontspec
COMMENT=	Advanced font selection in XeLaTeX and LuaLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-euenc-[0-9]*:../../fonts/tex-euenc
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-luaotfload-[0-9]*:../../fonts/tex-luaotfload
DEPENDS+=	tex-xunicode-[0-9]*:../../print/tex-xunicode

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
