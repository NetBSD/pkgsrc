# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:54 rillig Exp $

DISTNAME=	context-rst
PKGNAME=	tex-${DISTNAME}-0.6c
TEXLIVE_REV=	33092

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-rst
COMMENT=	Process reStructuredText with ConTeXt
LICENSE=	2-clause-bsd

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
