# $NetBSD: Makefile,v 1.5 2015/05/05 17:15:08 wiz Exp $

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	36465

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etex-pkg
COMMENT=	E-TeX support package
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
