# $NetBSD: Makefile,v 1.8 2016/06/16 03:57:30 markd Exp $

DISTNAME=	mflogo
# should be 
#PKGNAME=	tex-${DISTNAME}-2.0
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	38628

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mflogo
COMMENT=	LaTeX support for MetaFont logo fonts
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb15

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
