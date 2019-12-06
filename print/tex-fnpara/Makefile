# $NetBSD: Makefile,v 1.3 2019/12/06 20:21:26 markd Exp $

DISTNAME=	fnpara
PKGNAME=	tex-${DISTNAME}-2012
TEXLIVE_REV=	25607

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX package to typeset footnotes in paragraphs
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
