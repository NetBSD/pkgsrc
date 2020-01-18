# $NetBSD: Makefile,v 1.5 2020/01/18 23:34:47 rillig Exp $

DISTNAME=	schwalbe-chess
PKGNAME=	tex-${DISTNAME}-2.3
TEXLIVE_REV=	49602

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/schwalbe-chess
COMMENT=	Typeset the German chess magazine "Die Schwalbe"
LICENSE=	lppl-1.2

DEPENDS+=	tex-chess-problem-diagrams-[0-9]*:../../print/tex-chess-problem-diagrams

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
