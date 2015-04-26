# $NetBSD: Makefile,v 1.1 2015/04/26 01:33:23 markd Exp $

DISTNAME=	fonts-tlwg
PKGNAME=	tex-${DISTNAME}-0.6.1
TEXLIVE_REV=	34560

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Thai fonts for LaTeX from TLWG
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	nectec.map
TEX_MAP_FILES+=	nf.map
TEX_MAP_FILES+=	sipa.map
TEX_MAP_FILES+=	tlwg.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
