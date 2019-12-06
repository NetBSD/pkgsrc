# $NetBSD: Makefile,v 1.9 2019/12/06 20:23:33 markd Exp $

DISTNAME=	toptesi
PKGNAME=	tex-${DISTNAME}-6.3.06
TEXLIVE_REV=	51743

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/toptesi
COMMENT=	Bundle for typesetting multilanguage theses
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
