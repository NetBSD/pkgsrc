# $NetBSD: Makefile,v 1.1 2021/02/21 10:57:48 markd Exp $

DISTNAME=	zxjatype
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	53500

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/zxjatype
COMMENT=	Standard conforming typesetting of Japanese, for XeLaTeX
LICENSE=	mit

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
