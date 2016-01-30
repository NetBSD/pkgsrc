# $NetBSD: Makefile,v 1.2 2016/01/30 04:56:43 markd Exp $

DISTNAME=	lh.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.5g
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-lh
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb24

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
