# $NetBSD: Makefile,v 1.4 2018/03/24 16:50:29 joerg Exp $

DISTNAME=	skak
PKGNAME=	tex-${DISTNAME}-1.5.2
PKGREVISION=	1
TEXLIVE_REV=	32758

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/skak
COMMENT=	LaTeX fonts and macros for typesetting chess games
LICENSE=	lppl-1.3c

DEPENDS+=	tex-chessfss-[0-9]*:../../print/tex-chessfss
DEPENDS+=	tex-lambda-lists-[0-9]*:../../print/tex-lambda-lists

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
