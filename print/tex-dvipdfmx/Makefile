# $NetBSD: Makefile,v 1.5 2013/11/17 17:27:35 minskim Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	31830

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipdfmx

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-dvipdfmx-def-[0-9]*:../../print/tex-dvipdfmx-def

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvipdfmx

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
