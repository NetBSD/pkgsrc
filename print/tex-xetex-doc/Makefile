# $NetBSD: Makefile,v 1.7 2020/05/05 12:01:06 markd Exp $

DISTNAME=	xetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2020
TEXLIVE_REV=	54276

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xetex
COMMENT=	Documentation for tex-xetex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
