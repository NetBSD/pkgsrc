# $NetBSD: Makefile,v 1.4 2020/01/18 23:33:53 rillig Exp $

DISTNAME=	context-letter
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47085

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context-letter
COMMENT=	ConTeXt package for writing letters
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-context-[0-9]*:../../print/tex-context

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
