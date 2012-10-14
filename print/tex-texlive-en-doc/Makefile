# $NetBSD: Makefile,v 1.5 2012/10/14 17:07:58 minskim Exp $

DISTNAME=	texlive-en.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2012
TEXLIVE_REV=	26703

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX Live manual (English)

DEPENDS+=	tex-texlive-common-doc>=2012:../../print/tex-texlive-common-doc

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
