# $NetBSD: Makefile,v 1.14 2026/03/31 08:01:43 markd Exp $

DISTNAME=	pgfplots
PKGNAME=	tex-${DISTNAME}-1.18.2
TEXLIVE_REV=	77682

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pgfplots
COMMENT=	Create normal/logarithmic plots in two and three dimensions
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

REPLACE_INTERPRETER+=	luatex
REPLACE.luatex.old=	/usr/bin/luatex
REPLACE.luatex.new=	${PREFIX}/bin/luatex
REPLACE_FILES.luatex=	tex/generic/pgfplots/lua/prepcontour*

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
