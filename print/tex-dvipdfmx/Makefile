# $NetBSD: Makefile,v 1.16 2026/04/03 05:55:30 markd Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78409

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
