# $NetBSD: Makefile,v 1.6 2017/08/17 03:50:19 markd Exp $

DISTNAME=	microtype.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.7
TEXLIVE_REV=	44791

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/microtype
COMMENT=	Documentation for tex-microtype
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
