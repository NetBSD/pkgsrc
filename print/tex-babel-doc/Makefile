# $NetBSD: Makefile,v 1.8 2017/08/17 03:05:36 markd Exp $

DISTNAME=	babel.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.12
TEXLIVE_REV=	44722

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/babel
COMMENT=	Documentation for tex-babel
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
