# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:17 markd Exp $

DISTNAME=	context-ruby
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	28434

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-ruby
COMMENT=	Ruby annotations in ConTeXt
LICENSE=	public-domain

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
