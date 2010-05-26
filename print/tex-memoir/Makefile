# $NetBSD: Makefile,v 1.3 2010/05/26 05:11:25 minskim Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-1.618033988c.6.0f
TEXLIVE_REV=	17927

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset fiction, non-fiction and mathematical books

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
