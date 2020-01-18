# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:10 rillig Exp $

DISTNAME=	flowfram
PKGNAME=	tex-${DISTNAME}-1.17
TEXLIVE_REV=	35291

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/flowfram
COMMENT=	Create text frames for posters, brochures or magazines
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xfor-[0-9]*:../../print/tex-xfor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
