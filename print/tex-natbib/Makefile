# $NetBSD: Makefile,v 1.7 2019/12/06 20:22:52 markd Exp $

DISTNAME=	natbib
PKGNAME=	tex-${DISTNAME}-8.31b
TEXLIVE_REV=	20668

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible bibliography support for BibTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
