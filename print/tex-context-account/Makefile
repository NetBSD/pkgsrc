# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:49 rillig Exp $

DISTNAME=	context-account
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	23167

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-account
COMMENT=	Simple accounting package for ConTeXt
LICENSE=	public-domain

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
