# $NetBSD: Makefile,v 1.1.1.1 2011/10/26 20:33:12 minskim Exp $

DISTNAME=	epstopdf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.16
TEXLIVE_REV=	19287

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-epstopdf

CONFLICTS=	texlive-pdftools<2011

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
