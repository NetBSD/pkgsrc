# $NetBSD: Makefile,v 1.8 2021/06/06 11:34:20 markd Exp $

DISTNAME=	context-vim
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	59432

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-vim
COMMENT=	Generate ConTeXt syntax highlighting code from vim
LICENSE=	modified-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
DEPENDS+=	tex-context-filter-[0-9]*:../../print/tex-context-filter

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
