# $NetBSD: Makefile,v 1.11 2021/04/06 15:03:32 adam Exp $

DISTNAME=	minted
PKGNAME=	tex-${DISTNAME}-2.5
PKGREVISION=	1
TEXLIVE_REV=	44855

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/minted
COMMENT=	Highlighted source code for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-ifplatform-[0-9]*:../../print/tex-ifplatform
DEPENDS+=	tex-lineno-[0-9]*:../../print/tex-lineno
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

TEXLIVE_UNVERSIONED=	yes

PYTHON_VERSIONED_DEPENDENCIES=	pygments

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
