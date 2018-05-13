# $NetBSD: Makefile,v 1.1 2018/05/13 11:38:40 markd Exp $

DISTNAME=	translator
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	46231

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/translator
COMMENT=	Easy translation of strings in LaTeX
LICENSE=	gnu-gpl-v2 AND lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
