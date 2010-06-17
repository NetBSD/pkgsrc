# $NetBSD: Makefile,v 1.1.1.1 2010/06/17 00:00:31 minskim Exp $

DISTNAME=	context.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009
TEXLIVE_REV=	16044

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-context

CONFLICTS+=	teTeX-texmf<=3.0nb25
CONFLICTS+=	texlive-tetex<=2009

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
