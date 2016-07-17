# $NetBSD: Makefile,v 1.1 2016/07/17 21:59:33 wiz Exp $

DISTNAME=	context-vim
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	37413

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-vim
COMMENT=	Generate ConTeXt syntax highlighting code from vim
LICENSE=	modified-bsd

DEPENDS+=	tex-context-filter-[0-9]*:../../print/tex-context-filter
DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
