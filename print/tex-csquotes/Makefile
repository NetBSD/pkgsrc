# $NetBSD: Makefile,v 1.11 2020/05/01 00:15:12 markd Exp $

DISTNAME=	csquotes
PKGNAME=	tex-${DISTNAME}-5.2j
TEXLIVE_REV=	53041

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
