# $NetBSD: Makefile,v 1.9 2019/01/29 10:10:18 markd Exp $

DISTNAME=	fixme
PKGNAME=	tex-${DISTNAME}-4.5
TEXLIVE_REV=	49591

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fixme
COMMENT=	Insert "fixme" notes into draft documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-changebar-[0-9]*:../../print/tex-changebar
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-marginnote-[0-9]*:../../print/tex-marginnote
DEPENDS+=	tex-pdfcomment-[0-9]*:../../print/tex-pdfcomment
DEPENDS+=	tex-tools>=2010:../../print/tex-tools
DEPENDS+=	tex-xcolor>=2.11:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval>=2.6a:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
