# $NetBSD: Makefile,v 1.5 2020/04/26 12:21:17 markd Exp $

DISTNAME=	mathpazo
PKGNAME=	tex-${DISTNAME}-1.003.52663
TEXLIVE_REV=	52663

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathpazo
COMMENT=	Fonts to typeset mathematics to match Palatino
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-fpl-[0-9]*:../../fonts/tex-fpl
DEPENDS+=	tex-palatino-[0-9]*:../../fonts/tex-palatino

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
