# $NetBSD: Makefile,v 1.5 2017/06/20 21:01:17 markd Exp $

DISTNAME=	beamer
PKGNAME=	tex-${DISTNAME}-3.41
TEXLIVE_REV=	43073

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/beamer
COMMENT=	LaTeX class for producing presentations and slides
LICENSE=	lppl-1.3c OR gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
