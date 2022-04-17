# $NetBSD: Makefile,v 1.14 2022/04/17 10:18:56 markd Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	61101

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvipdfmx
COMMENT=	Supplementary files for dvipdfmx
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvipdfmx/dvipdfmx.cfg
TEXLIVE_IGNORE_PATTERNS+=	tlpkg/tlpostcode

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
