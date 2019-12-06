# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:40 markd Exp $

DISTNAME=	tikzorbital
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	36439

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tikzorbital
COMMENT=	Atomic and molecular orbitals using TiKZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
