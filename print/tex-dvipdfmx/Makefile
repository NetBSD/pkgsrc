# $NetBSD: Makefile,v 1.12 2020/01/18 23:34:01 rillig Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2016.41623
TEXLIVE_REV=	41623

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvipdfmx
COMMENT=	Supplementary files for dvipdfmx
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvipdfmx
TEXLIVE_IGNORE_PATTERNS+=	tlpkg/tlpostcode

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
