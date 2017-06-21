# $NetBSD: Makefile,v 1.10 2017/06/21 13:25:35 markd Exp $

DISTNAME=	tools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2017
TEXLIVE_REV=	43813

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-tools
COMMENT=	Documentation for tex-tools
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
