# $NetBSD: Makefile,v 1.5 2022/04/14 03:42:24 markd Exp $

DISTNAME=	translator
PKGNAME=	tex-${DISTNAME}-1.12d
TEXLIVE_REV=	59412

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/translator
COMMENT=	Easy translation of strings in LaTeX
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
