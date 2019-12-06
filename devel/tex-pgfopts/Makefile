# $NetBSD: Makefile,v 1.2 2019/12/06 19:18:35 markd Exp $

DISTNAME=	pgfopts
PKGNAME=	tex-${DISTNAME}-2.1a
TEXLIVE_REV=	34573

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX package options with pgfkeys
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
