# $NetBSD: Makefile,v 1.1.1.1 2011/11/05 13:35:34 minskim Exp $

DISTNAME=	csquotes
PKGNAME=	tex-${DISTNAME}-5.1d
TEXLIVE_REV=	24393

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Context sensitive quotation facilities

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
