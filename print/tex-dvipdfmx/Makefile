# $NetBSD: Makefile,v 1.9 2016/06/16 04:06:02 markd Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	41149

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvipdfmx
COMMENT=	Supplementary files for dvipdfmx
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-dvipdfmx-def-[0-9]*:../../print/tex-dvipdfmx-def

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvipdfmx
TEXLIVE_IGNORE_PATTERNS+=	tlpkg/tlpostcode

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
