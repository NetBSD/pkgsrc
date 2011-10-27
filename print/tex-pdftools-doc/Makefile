# $NetBSD: Makefile,v 1.1.1.1 2011/10/27 19:03:37 minskim Exp $

DISTNAME=	pdftools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.82
TEXLIVE_REV=	23089

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pdftools
LICENSE=	public-domain

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEXLIVE_IGNORE_PATTERNS+=	texmf/doc/man/man1/pdf*

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
