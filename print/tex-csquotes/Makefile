# $NetBSD: Makefile,v 1.4 2016/06/16 04:06:02 markd Exp $

DISTNAME=	csquotes
PKGNAME=	tex-${DISTNAME}-5.1g
TEXLIVE_REV=	39538

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/csquotes
COMMENT=	Context sensitive quotation facilities
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
