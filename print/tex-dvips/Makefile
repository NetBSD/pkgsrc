# $NetBSD: Makefile,v 1.22 2017/09/06 16:49:33 wiz Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2017
TEXLIVE_REV=	44167

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvips
COMMENT=	Files for a DVI to PostScript driver
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
