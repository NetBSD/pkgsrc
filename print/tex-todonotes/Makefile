# $NetBSD: Makefile,v 1.2 2017/06/21 13:25:34 markd Exp $

DISTNAME=	todonotes
PKGNAME=	tex-${DISTNAME}-1.0.5
TEXLIVE_REV=	42423

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/henrikmidtiby/todonotes
COMMENT=	Marking things to do in a LaTeX document
LICENSE=	lppl-1.2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
