# $NetBSD: Makefile,v 1.1.1.1 2012/03/22 08:10:18 markd Exp $

DISTNAME=	minted
PKGNAME=	tex-${DISTNAME}-1.7
TEXLIVE_REV=	24002

MAINTAINER=	markd@NetBSD.org
COMMENT=	Highlighted source code for LaTeX

DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

.include "../../print/texlive/package.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
