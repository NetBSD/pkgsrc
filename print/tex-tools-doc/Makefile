# $NetBSD: Makefile,v 1.9 2016/08/07 09:09:41 markd Exp $

DISTNAME=	tools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016.41688
TEXLIVE_REV=	41688

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-tools
COMMENT=	Documentation for tex-tools
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
