# $NetBSD: Makefile,v 1.10 2019/12/06 20:19:20 markd Exp $

DISTNAME=	csquotes
PKGNAME=	tex-${DISTNAME}-5.2e
TEXLIVE_REV=	51091

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/csquotes
COMMENT=	Context sensitive quotation facilities
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
