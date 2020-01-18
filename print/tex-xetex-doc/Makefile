# $NetBSD: Makefile,v 1.6 2020/01/18 23:35:03 rillig Exp $

DISTNAME=	xetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2018
TEXLIVE_REV=	45931

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xetex
COMMENT=	Documentation for tex-xetex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
