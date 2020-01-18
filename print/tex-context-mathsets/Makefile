# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:54 rillig Exp $

DISTNAME=	context-mathsets
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	23167

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-mathsets
COMMENT=	Set notation in ConTeXt
LICENSE=	2-clause-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
