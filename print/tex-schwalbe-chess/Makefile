# $NetBSD: Makefile,v 1.2 2016/06/16 04:06:15 markd Exp $

DISTNAME=	schwalbe-chess
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	39318

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/schwalbe-chess
COMMENT=	Typeset the German chess magazine "Die Schwalbe"
LICENSE=	lppl-1.2

DEPENDS+=	tex-chess-problem-diagrams-[0-9]*:../../print/tex-chess-problem-diagrams

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
