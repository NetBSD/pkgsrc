# $NetBSD: Makefile,v 1.2 2015/04/23 12:27:54 markd Exp $

DISTNAME=	minted
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	36197

MAINTAINER=	markd@NetBSD.org
COMMENT=	Highlighted source code for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

.include "../../print/texlive/package.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
