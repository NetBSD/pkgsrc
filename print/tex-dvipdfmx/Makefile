# $NetBSD: Makefile,v 1.7 2015/05/05 16:52:44 wiz Exp $

DISTNAME=	dvipdfmx
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35703

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvipdfmx
COMMENT=	Supplementary files for dvipdfmx
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-glyphlist-[0-9]*:../../fonts/tex-glyphlist
DEPENDS+=	tex-dvipdfmx-def-[0-9]*:../../print/tex-dvipdfmx-def

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvipdfmx

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
