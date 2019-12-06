# $NetBSD: Makefile,v 1.24 2019/12/06 20:23:30 markd Exp $

DISTNAME=	textpos
PKGNAME=	tex-${DISTNAME}-1.9.1
TEXLIVE_REV=	50988

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/textpos
COMMENT=	Place boxes at arbitrary positions on the LaTeX page
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
