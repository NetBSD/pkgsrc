# $NetBSD: Makefile,v 1.1 2022/08/21 17:12:39 wiz Exp $

DISTNAME=	xepersian-hm
PKGNAME=	tex-${DISTNAME}-1.1a
TEXLIVE_REV=	56272

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dma8hm1334.bitbucket.io/
COMMENT=	Fixes kashida feature in xepersian package
LICENSE=	lppl-1.3c

# graphicx
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
# expl3
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
# l3keys2e
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xepersian-[0-9]*:../../print/tex-xepersian
# zref-savepos
DEPENDS+=	tex-zref-[0-9]*:../../print/tex-zref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
