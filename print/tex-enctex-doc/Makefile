# $NetBSD: Makefile,v 1.6 2015/05/05 17:02:21 wiz Exp $

DISTNAME=	enctex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	34957

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/enctex
COMMENT=	Documentation for tex-enctex
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb15

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
