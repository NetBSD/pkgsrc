# $NetBSD: Makefile,v 1.2 2019/12/06 19:30:14 markd Exp $

DISTNAME=	mathalpha
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	51179

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathalpha
COMMENT=	General package for loading maths alphabets in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
