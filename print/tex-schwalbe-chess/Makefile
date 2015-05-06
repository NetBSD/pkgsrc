# $NetBSD: Makefile,v 1.1 2015/05/06 08:46:49 wiz Exp $

DISTNAME=	schwalbe-chess
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	36309

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/schwalbe-chess
COMMENT=	Typeset the German chess magazine "Die Schwalbe"
#LICENSE=	lppl1.2

DEPENDS+=	tex-chess-problem-diagrams-[0-9]*:../../print/tex-chess-problem-diagrams

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
