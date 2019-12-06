# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:32 markd Exp $

DISTNAME=	todonotes
PKGNAME=	tex-${DISTNAME}-1.1.2
TEXLIVE_REV=	49820

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/henrikmidtiby/todonotes
COMMENT=	Marking things to do in a LaTeX document
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
