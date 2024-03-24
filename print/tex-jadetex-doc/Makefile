# $NetBSD: Makefile,v 1.4 2024/03/24 10:44:39 markd Exp $

DISTNAME=	jadetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.13.70002
TEXLIVE_REV=	70002

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jadetex
COMMENT=	Documentation for tex-jadetex

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
