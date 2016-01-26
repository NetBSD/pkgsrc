# $NetBSD: Makefile,v 1.4 2016/01/26 10:18:26 markd Exp $

DISTNAME=	xltxtra
PKGNAME=	tex-${DISTNAME}-0.5e
TEXLIVE_REV=	19809

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extras files for LaTeX users of XeTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-metalogo-[0-9]*:../../print/tex-metalogo
DEPENDS+=	tex-realscripts-[0-9]*:../../print/tex-realscripts
DEPENDS+=	tex-xetex-[0-9]*:../../print/tex-xetex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
