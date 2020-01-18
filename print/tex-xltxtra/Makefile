# $NetBSD: Makefile,v 1.8 2020/01/18 23:35:04 rillig Exp $

DISTNAME=	xltxtra
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	49555

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xltxtra
COMMENT=	Extras files for LaTeX users of XeTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-metalogo-[0-9]*:../../print/tex-metalogo
DEPENDS+=	tex-realscripts-[0-9]*:../../print/tex-realscripts
DEPENDS+=	tex-xetex-[0-9]*:../../print/tex-xetex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
