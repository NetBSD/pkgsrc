# $NetBSD: Makefile,v 1.6 2015/05/05 16:45:57 wiz Exp $

DISTNAME=	cm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	32865

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cm
COMMENT=	Documentation for tex-cm
#LICENSE=	knuth

CONFLICTS+=	teTeX-texmf<=3.0nb22

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
