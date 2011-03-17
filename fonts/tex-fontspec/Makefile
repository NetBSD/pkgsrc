# $NetBSD: Makefile,v 1.5 2011/03/17 17:58:04 minskim Exp $

DISTNAME=	fontspec
PKGNAME=	tex-${DISTNAME}-2.1f
TEXLIVE_REV=	21527

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Advanced font selection in XeLaTeX and LuaLaTeX

DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
