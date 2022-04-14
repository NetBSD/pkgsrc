# $NetBSD: Makefile,v 1.8 2022/04/14 03:36:05 markd Exp $

DISTNAME=	todonotes
PKGNAME=	tex-${DISTNAME}-1.1.5
TEXLIVE_REV=	59465

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/todonotes
COMMENT=	Marking things to do in a LaTeX document
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
