# $NetBSD: Makefile,v 1.6 2020/05/21 10:24:36 markd Exp $

DISTNAME=	context-vim
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	55204

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-vim
COMMENT=	Generate ConTeXt syntax highlighting code from vim
LICENSE=	modified-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
DEPENDS+=	tex-context-filter-[0-9]*:../../print/tex-context-filter

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
