# $NetBSD: Makefile,v 1.22 2024/02/18 10:04:29 markd Exp $

DISTNAME=	fontspec
PKGNAME=	tex-${DISTNAME}-2.9a
TEXLIVE_REV=	69880

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
