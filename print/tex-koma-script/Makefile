# $NetBSD: Makefile,v 1.30 2026/03/29 19:55:55 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.49.2
TEXLIVE_REV=	77575

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-xpatch-[0-9]*:../../print/tex-xpatch

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
