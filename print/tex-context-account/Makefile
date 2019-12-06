# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:12 markd Exp $

DISTNAME=	context-account
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	23167

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-account
COMMENT=	Simple accounting package for ConTeXt
LICENSE=	public-domain

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
