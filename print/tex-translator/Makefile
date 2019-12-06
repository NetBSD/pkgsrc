# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:35 markd Exp $

DISTNAME=	translator
PKGNAME=	tex-${DISTNAME}-1.12a
TEXLIVE_REV=	51279

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/translator
COMMENT=	Easy translation of strings in LaTeX
LICENSE=	gnu-gpl-v2 AND lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
