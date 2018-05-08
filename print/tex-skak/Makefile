# $NetBSD: Makefile,v 1.5 2018/05/08 11:19:35 markd Exp $

DISTNAME=	skak
PKGNAME=	tex-${DISTNAME}-1.5.3
TEXLIVE_REV=	46259

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/skak
COMMENT=	LaTeX fonts and macros for typesetting chess games
LICENSE=	lppl-1.3c

DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-chessfss

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
