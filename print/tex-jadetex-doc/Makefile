# $NetBSD: Makefile,v 1.3 2021/02/14 03:04:33 markd Exp $

DISTNAME=	jadetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.13.57186
TEXLIVE_REV=	57186

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jadetex
COMMENT=	Documentation for tex-jadetex

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
