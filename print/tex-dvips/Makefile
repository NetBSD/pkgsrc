# $NetBSD: Makefile,v 1.23 2019/12/06 20:19:27 markd Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2017
TEXLIVE_REV=	44167

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvips
COMMENT=	Files for a DVI to PostScript driver
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvips/base

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
