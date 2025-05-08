# $NetBSD: Makefile,v 1.15 2025/05/08 12:10:08 markd Exp $

DISTNAME=	csquotes
PKGNAME=	tex-${DISTNAME}-5.2o
TEXLIVE_REV=	71053

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/csquotes
COMMENT=	Context sensitive quotation facilities
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
