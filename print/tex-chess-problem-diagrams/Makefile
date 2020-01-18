# $NetBSD: Makefile,v 1.5 2020/01/18 23:33:46 rillig Exp $

DISTNAME=	chess-problem-diagrams
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	39317

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/chess-problem-diagrams
COMMENT=	Package for typesetting chess problem diagrams
LICENSE=	lppl-1.2

DEPENDS+=	tex-bartel-chess-fonts-[0-9]*:../../fonts/tex-bartel-chess-fonts

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
