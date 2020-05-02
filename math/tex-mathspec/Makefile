# $NetBSD: Makefile,v 1.4 2020/05/02 03:13:54 markd Exp $

DISTNAME=	mathspec
PKGNAME=	tex-${DISTNAME}-0.2b
PKGREVISION=	1
TEXLIVE_REV=	42773

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathspec
COMMENT=	Specify arbitrary fonts for mathematics in XeTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
