# $NetBSD: Makefile,v 1.11 2017/06/21 08:28:42 markd Exp $

DISTNAME=	latex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-20170101.1
TEXLIVE_REV=	43813

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex
COMMENT=	Documentation for tex-latex
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb22

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
