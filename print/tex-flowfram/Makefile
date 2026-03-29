# $NetBSD: Makefile,v 1.4 2026/03/29 03:35:09 markd Exp $

DISTNAME=	flowfram
PKGNAME=	tex-${DISTNAME}-2.1
TEXLIVE_REV=	78101

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/flowfram
COMMENT=	Create text frames for posters, brochures or magazines
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-rerunfilecheck-[0-9]*:../../print/tex-rerunfilecheck
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xfor-[0-9]*:../../print/tex-xfor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
