# $NetBSD: Makefile,v 1.8 2015/06/14 12:50:02 markd Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	37159

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvipdfmx
COMMENT=	Supplementary files for dvipdfmx
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-dvipdfmx-def-[0-9]*:../../print/tex-dvipdfmx-def

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvipdfmx

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
