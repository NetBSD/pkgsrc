# $NetBSD: Makefile,v 1.8 2016/08/07 09:09:38 markd Exp $

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	41784

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etex-pkg
COMMENT=	E-TeX support package
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
