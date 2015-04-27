# $NetBSD: Makefile,v 1.1 2015/04/27 06:50:30 markd Exp $

DISTNAME=	crop
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD,org
COMMENT=	Support for cropmarks
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb43
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
