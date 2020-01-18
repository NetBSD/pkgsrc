# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:54 rillig Exp $

DISTNAME=	context-ruby
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	28434

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-ruby
COMMENT=	Ruby annotations in ConTeXt
LICENSE=	public-domain

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
