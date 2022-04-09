# $NetBSD: Makefile,v 1.9 2022/04/09 20:50:37 markd Exp $

DISTNAME=	context-vim
PKGNAME=	tex-${DISTNAME}-2021.62071
TEXLIVE_REV=	62071

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-vim
COMMENT=	Generate ConTeXt syntax highlighting code from vim
LICENSE=	modified-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
DEPENDS+=	tex-context-filter-[0-9]*:../../print/tex-context-filter

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
