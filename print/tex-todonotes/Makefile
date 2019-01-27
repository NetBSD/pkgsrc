# $NetBSD: Makefile,v 1.3 2019/01/27 05:23:59 markd Exp $

DISTNAME=	todonotes
PKGNAME=	tex-${DISTNAME}-1.1.1
TEXLIVE_REV=	49233

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/henrikmidtiby/todonotes
COMMENT=	Marking things to do in a LaTeX document
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
