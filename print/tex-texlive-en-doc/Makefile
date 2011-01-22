# $NetBSD: Makefile,v 1.3 2011/01/22 23:27:46 minskim Exp $

DISTNAME=	texlive-en.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2010.20605
TEXLIVE_REV=	20605

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX Live manual (English)

DEPENDS+=	tex-texlive-common-doc-[0-9]*:../../print/tex-texlive-common-doc

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
