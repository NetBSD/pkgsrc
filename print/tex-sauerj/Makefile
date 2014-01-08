# $NetBSD: Makefile,v 1.1 2014/01/08 02:01:23 minskim Exp $

DISTNAME=	sauerj
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bundle of utilities by Jonathan Sauer
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
