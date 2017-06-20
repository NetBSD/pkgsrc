# $NetBSD: Makefile,v 1.8 2017/06/20 22:07:25 markd Exp $

DISTNAME=	context.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2017
TEXLIVE_REV=	44436

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context
COMMENT=	Documentation for tex-context

CONFLICTS+=	teTeX-texmf<=3.0nb29
CONFLICTS+=	texlive-tetex<=2009

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
