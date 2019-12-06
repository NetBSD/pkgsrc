# $NetBSD: Makefile,v 1.3 2019/12/06 20:19:16 markd Exp $

DISTNAME=	context-mathsets
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	23167

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/context-mathsets
COMMENT=	Set notation in ConTeXt
LICENSE=	2-clause-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
