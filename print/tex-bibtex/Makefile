# $NetBSD: Makefile,v 1.9 2019/12/06 20:19:00 markd Exp $

DISTNAME=	bibtex
PKGNAME=	tex-${DISTNAME}-0.99d
PKGREVISION=	2
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/bibtex
COMMENT=	Reference management software for LaTeX
#LICENSE=	knuth

DEPENDS+=	web2c>=2013:../../print/web2c
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
