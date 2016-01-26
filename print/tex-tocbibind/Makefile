# $NetBSD: Makefile,v 1.3 2016/01/26 10:51:41 markd Exp $

DISTNAME=	tocbibind
PKGNAME=	tex-${DISTNAME}-1.5k
TEXLIVE_REV=	20085

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Add bibliography/index/contents to Table of Contents
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb27
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
