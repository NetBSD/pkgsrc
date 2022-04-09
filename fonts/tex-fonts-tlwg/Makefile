# $NetBSD: Makefile,v 1.9 2022/04/09 21:04:06 markd Exp $

DISTNAME=	fonts-tlwg
PKGNAME=	tex-${DISTNAME}-0.7.3
TEXLIVE_REV=	60817

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fonts-tlwg
COMMENT=	Thai fonts for LaTeX from TLWG
LICENSE=	gnu-gpl-v2 AND lppl-1.3c

TEX_MAP_FILES+=	nectec.map
TEX_MAP_FILES+=	nf.map
TEX_MAP_FILES+=	sipa.map
TEX_MAP_FILES+=	tlwg.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
