# $NetBSD: Makefile,v 1.3 2016/08/07 09:09:41 markd Exp $

DISTNAME=	toptesi
PKGNAME=	tex-${DISTNAME}-5.92
TEXLIVE_REV=	41656

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/toptesi
COMMENT=	Bundle for typesetting multilanguage theses
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
