# $NetBSD: Makefile,v 1.8 2012/10/16 20:38:54 minskim Exp $

DISTNAME=	luatex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.70.1pl26689
TEXLIVE_REV=	26689

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	Documentation for tex-luatex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
