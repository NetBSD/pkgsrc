# $NetBSD: Makefile,v 1.7 2021/02/15 04:25:52 markd Exp $

DISTNAME=	context-vim
PKGNAME=	tex-${DISTNAME}-2020.56356
TEXLIVE_REV=	56356

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-vim
COMMENT=	Generate ConTeXt syntax highlighting code from vim
LICENSE=	modified-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context
DEPENDS+=	tex-context-filter-[0-9]*:../../print/tex-context-filter

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
