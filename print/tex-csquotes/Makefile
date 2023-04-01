# $NetBSD: Makefile,v 1.14 2023/04/01 10:42:04 markd Exp $

DISTNAME=	csquotes
PKGNAME=	tex-${DISTNAME}-5.2n
TEXLIVE_REV=	64389

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
