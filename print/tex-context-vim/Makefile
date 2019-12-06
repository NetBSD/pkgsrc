# $NetBSD: Makefile,v 1.4 2019/12/06 20:19:19 markd Exp $

DISTNAME=	context-vim
PKGNAME=	tex-${DISTNAME}-2018.48391
TEXLIVE_REV=	48391

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-vim
COMMENT=	Generate ConTeXt syntax highlighting code from vim
LICENSE=	modified-bsd

DEPENDS+=	tex-context-filter-[0-9]*:../../print/tex-context-filter
DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
