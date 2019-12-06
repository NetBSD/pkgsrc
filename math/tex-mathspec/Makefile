# $NetBSD: Makefile,v 1.2 2019/12/06 19:07:33 markd Exp $

DISTNAME=	mathspec
PKGNAME=	tex-${DISTNAME}-0.2b
TEXLIVE_REV=	42773

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mathspec
COMMENT=	Specify arbitrary fonts for mathematics in XeTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
