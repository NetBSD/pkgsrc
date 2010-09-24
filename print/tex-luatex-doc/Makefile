# $NetBSD: Makefile,v 1.3 2010/09/24 21:16:27 minskim Exp $

DISTNAME=	luatex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.60.1
TEXLIVE_REV=	19324

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	Documentation for tex-luatex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
