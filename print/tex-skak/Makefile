# $NetBSD: Makefile,v 1.7 2020/01/18 23:34:49 rillig Exp $

DISTNAME=	skak
PKGNAME=	tex-${DISTNAME}-1.5.3
TEXLIVE_REV=	46259

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/skak
COMMENT=	LaTeX fonts and macros for typesetting chess games
LICENSE=	lppl-1.3c

DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-chessfss

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
