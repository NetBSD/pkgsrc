# $NetBSD: Makefile,v 1.2 2023/04/08 06:21:18 markd Exp $

DISTNAME=	bxbase
PKGNAME=	tex-${DISTNAME}-1.2a
TEXLIVE_REV=	66115

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxbase
COMMENT=	BX bundle base components
LICENSE=	mit

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
