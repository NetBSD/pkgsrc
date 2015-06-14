# $NetBSD: Makefile,v 1.8 2015/06/14 12:50:03 markd Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.0p.36834
TEXLIVE_REV=	36834

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/graphics
COMMENT=	Standard LaTeX graphics
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
