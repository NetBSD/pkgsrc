# $NetBSD: Makefile,v 1.2 2019/12/06 20:23:13 markd Exp $

DISTNAME=	sauerj
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bundle of utilities by Jonathan Sauer
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
