# $NetBSD: Makefile,v 1.2 2016/08/07 07:17:37 markd Exp $

DISTNAME=	fonts-tlwg
PKGNAME=	tex-${DISTNAME}-0.6.3
TEXLIVE_REV=	41366

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fonts-tlwg
COMMENT=	Thai fonts for LaTeX from TLWG
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	nectec.map
TEX_MAP_FILES+=	nf.map
TEX_MAP_FILES+=	sipa.map
TEX_MAP_FILES+=	tlwg.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
