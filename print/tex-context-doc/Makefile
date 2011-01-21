# $NetBSD: Makefile,v 1.2 2011/01/21 04:12:18 minskim Exp $

DISTNAME=	context.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2010
TEXLIVE_REV=	20438

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-context

CONFLICTS+=	teTeX-texmf<=3.0nb25
CONFLICTS+=	texlive-tetex<=2009

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
