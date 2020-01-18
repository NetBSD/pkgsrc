# $NetBSD: Makefile,v 1.4 2020/01/18 23:32:38 rillig Exp $

DISTNAME=	tkz-fct
PKGNAME=	tex-${DISTNAME}-1.16c
TEXLIVE_REV=	22831

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tkz-fct
COMMENT=	Tools for drawing graphs of functions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tkz-base-[0-9]*:../../graphics/tex-tkz-base

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
