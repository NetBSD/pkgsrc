# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:36 rillig Exp $

DISTNAME=	tikzorbital
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	36439

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikzorbital
COMMENT=	Atomic and molecular orbitals using TiKZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
