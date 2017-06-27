# $NetBSD: Makefile,v 1.7 2017/06/27 21:45:47 minskim Exp $

DISTNAME=	babel.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.10
PKGREVISION=	1
TEXLIVE_REV=	44427

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/babel
COMMENT=	Documentation for tex-babel
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
