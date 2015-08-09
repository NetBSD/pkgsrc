# $NetBSD: Makefile,v 1.3 2015/08/09 06:41:27 markd Exp $

DISTNAME=	csquotes
PKGNAME=	tex-${DISTNAME}-5.1f
TEXLIVE_REV=	37891

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
