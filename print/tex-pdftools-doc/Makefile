# $NetBSD: Makefile,v 1.2 2013/12/12 04:44:17 minskim Exp $

DISTNAME=	pdftools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.83
TEXLIVE_REV=	31660

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pdftools
LICENSE=	public-domain

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man/man1/pdf*

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
