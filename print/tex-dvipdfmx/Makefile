# $NetBSD: Makefile,v 1.6 2015/04/25 03:43:42 markd Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35703

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfmx

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-dvipdfmx-def-[0-9]*:../../print/tex-dvipdfmx-def

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvipdfmx

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
