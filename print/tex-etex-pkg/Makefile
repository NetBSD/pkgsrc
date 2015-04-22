# $NetBSD: Makefile,v 1.4 2015/04/22 22:22:45 markd Exp $

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	36465

MAINTAINER=	minskim@NetBSD.org
COMMENT=	E-TeX support package
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
