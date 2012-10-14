# $NetBSD: Makefile,v 1.2 2012/10/14 21:59:40 minskim Exp $

DISTNAME=	mptopdf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2012
TEXLIVE_REV=	26689

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-mptopdf

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
