# $NetBSD: Makefile,v 1.24 2020/01/18 23:34:02 rillig Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2017
TEXLIVE_REV=	44167

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvips
COMMENT=	Files for a DVI to PostScript driver
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvips/base

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
