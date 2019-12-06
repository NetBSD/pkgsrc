# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:21 markd Exp $

DISTNAME=	ellipse
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	39025

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/ellipse
COMMENT=	Draw ellipses and elliptical arcs using the standard LaTeX2e picture environment
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pict2e-[0-9]*:../../print/tex-pict2e

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
