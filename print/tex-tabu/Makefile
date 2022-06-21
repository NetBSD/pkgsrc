# $NetBSD: Makefile,v 1.7 2022/06/21 22:16:21 joerg Exp $

DISTNAME=	tabu
PKGNAME=	tex-${DISTNAME}-2.9
PKGREVISION=	1
TEXLIVE_REV=	49707

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tabu
COMMENT=	Flexible LaTeX tabulars
LICENSE=	lppl-1.3c

DEPENDS+=	tex-varwidth-[0-9]*:../../print/tex-varwidth

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
