# $NetBSD: Makefile,v 1.4 2015/04/22 10:12:41 markd Exp $

DISTNAME=	beamer
PKGNAME=	tex-${DISTNAME}-3.36
TEXLIVE_REV=	36461

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LaTeX class for producing presentations and slides
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb22
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
