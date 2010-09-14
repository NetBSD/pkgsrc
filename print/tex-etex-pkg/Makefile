# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:11 minskim Exp $

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	E-TeX support package

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
