# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:02 markd Exp $

DISTNAME=	pdftools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.86
TEXLIVE_REV=	37078

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pdftools
LICENSE=	public-domain

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man/man1/pdf*

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
