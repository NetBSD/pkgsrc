# $NetBSD: Makefile,v 1.29 2025/05/10 01:02:13 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.43
TEXLIVE_REV=	72643

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-xpatch-[0-9]*:../../print/tex-xpatch

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
