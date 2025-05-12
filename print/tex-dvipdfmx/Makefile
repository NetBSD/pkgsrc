# $NetBSD: Makefile,v 1.15 2025/05/12 11:44:57 markd Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	74096

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvipdfmx
COMMENT=	Supplementary files for dvipdfmx
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-extractbb-[0-9]*:../../print/tex-extractbb
DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def
DEPENDS+=	tex-texlive-scripts-extra-[0-9]*:../../print/tex-texlive-scripts-extra

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvipdfmx/dvipdfmx.cfg
TEXLIVE_IGNORE_PATTERNS+=	tlpkg/tlpostcode

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
