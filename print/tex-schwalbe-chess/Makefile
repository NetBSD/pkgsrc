# $NetBSD: Makefile,v 1.7 2022/09/01 11:14:10 markd Exp $

DISTNAME=	schwalbe-chess
PKGNAME=	tex-${DISTNAME}-2.12
TEXLIVE_REV=	63708

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/schwalbe-chess
COMMENT=	Typeset the German chess magazine "Die Schwalbe"
LICENSE=	lppl-1.2

DEPENDS+=	tex-chess-problem-diagrams-[0-9]*:../../print/tex-chess-problem-diagrams

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
