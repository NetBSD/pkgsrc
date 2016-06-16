# $NetBSD: Makefile,v 1.7 2016/06/16 04:06:03 markd Exp $

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.6
TEXLIVE_REV=	39355

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etex-pkg
COMMENT=	E-TeX support package
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
