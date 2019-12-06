# $NetBSD: Makefile,v 1.4 2019/12/06 20:04:38 markd Exp $

DISTNAME=	tex-ps
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX to PostScript generic macros and add-ons
LICENSE=	public-domain

DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
