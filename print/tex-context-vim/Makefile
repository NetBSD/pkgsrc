# $NetBSD: Makefile,v 1.2 2018/05/06 02:12:45 markd Exp $

DISTNAME=	context-vim
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47085

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-vim
COMMENT=	Generate ConTeXt syntax highlighting code from vim
LICENSE=	modified-bsd

DEPENDS+=	tex-context-filter-[0-9]*:../../print/tex-context-filter
DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
