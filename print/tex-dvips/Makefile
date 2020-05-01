# $NetBSD: Makefile,v 1.25 2020/05/01 00:15:13 markd Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	54279

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvips
COMMENT=	Files for a DVI to PostScript driver
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
