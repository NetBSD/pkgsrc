# $NetBSD: Makefile,v 1.9 2016/06/16 04:06:04 markd Exp $

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.0r
TEXLIVE_REV=	41015

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/graphics
COMMENT=	Standard LaTeX graphics
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
