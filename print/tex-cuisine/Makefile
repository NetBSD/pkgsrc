# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:58 rillig Exp $

DISTNAME=	cuisine
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	34453

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cuisine
COMMENT=	Typeset recipes in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-units-[0-9]*:../../print/tex-units

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
