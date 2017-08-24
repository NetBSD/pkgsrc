# $NetBSD: Makefile,v 1.7 2017/08/24 00:04:12 markd Exp $

DISTNAME=	minted
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	44855

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/minted
COMMENT=	Highlighted source code for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-ifplatform-[0-9]*:../../print/tex-ifplatform
DEPENDS+=	tex-lineno-[0-9]*:../../print/tex-lineno
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

.include "../../print/texlive/package.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
