# $NetBSD: Makefile,v 1.1 2022/04/18 03:06:43 markd Exp $

DISTNAME=	etextools
PKGNAME=	tex-${DISTNAME}-3.1415926
TEXLIVE_REV=	20694

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/etextools
COMMENT=	e-TeX tools for LaTeX users and package writers
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-letltxmacro-[0-9]*:../../print/tex-letltxmacro

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
