# $NetBSD: Makefile,v 1.7 2016/06/16 04:06:02 markd Exp $

DISTNAME=	context.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016
TEXLIVE_REV=	41282

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context
COMMENT=	Documentation for tex-context

CONFLICTS+=	teTeX-texmf<=3.0nb29
CONFLICTS+=	texlive-tetex<=2009

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
