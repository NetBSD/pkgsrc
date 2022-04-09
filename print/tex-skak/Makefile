# $NetBSD: Makefile,v 1.8 2022/04/09 03:14:52 markd Exp $

DISTNAME=	skak
PKGNAME=	tex-${DISTNAME}-1.5.3.61719
TEXLIVE_REV=	61719

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/skak
COMMENT=	LaTeX fonts and macros for typesetting chess games
LICENSE=	lppl-1.3c

DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-chessfss

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
