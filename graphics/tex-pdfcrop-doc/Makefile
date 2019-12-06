# $NetBSD: Makefile,v 1.4 2019/12/06 20:04:29 markd Exp $

DISTNAME=	pdfcrop.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.37
TEXLIVE_REV=	29348

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pdfcrop
LICENSE=	lppl-1.3c

TEX_TEXMF_DIRS=	texmf-dist

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
