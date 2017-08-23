# $NetBSD: Makefile,v 1.6 2017/08/23 23:34:54 markd Exp $

DISTNAME=	beamer
PKGNAME=	tex-${DISTNAME}-3.42
TEXLIVE_REV=	44798

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/beamer
COMMENT=	LaTeX class for producing presentations and slides
LICENSE=	lppl-1.3c OR gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
