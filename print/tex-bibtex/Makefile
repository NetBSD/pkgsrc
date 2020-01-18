# $NetBSD: Makefile,v 1.10 2020/01/18 23:33:42 rillig Exp $

DISTNAME=	bibtex
PKGNAME=	tex-${DISTNAME}-0.99d
PKGREVISION=	2
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bibtex
COMMENT=	Reference management software for LaTeX
#LICENSE=	knuth

DEPENDS+=	web2c>=2013:../../print/web2c
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
