# $NetBSD: Makefile,v 1.7 2015/04/26 01:18:22 markd Exp $

DISTNAME=	fontspec
PKGNAME=	tex-${DISTNAME}-2.4c
TEXLIVE_REV=	36512

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Advanced font selection in XeLaTeX and LuaLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-euenc-[0-9]*:../../fonts/tex-euenc
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-luaotfload-[0-9]*:../../fonts/tex-luaotfload
DEPENDS+=	tex-xunicode-[0-9]*:../../print/tex-xunicode

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
