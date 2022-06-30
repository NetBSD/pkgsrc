# $NetBSD: Makefile,v 1.13 2022/06/30 11:18:46 nia Exp $

DISTNAME=	minted
PKGNAME=	tex-${DISTNAME}-2.6
PKGREVISION=	1
TEXLIVE_REV=	61405

MAINTAINER=	pkgsrc-users@NetBSD.org
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

PYTHON_VERSIONED_DEPENDENCIES=	pygments

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
