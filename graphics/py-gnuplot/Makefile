# $NetBSD: Makefile,v 1.1.1.1 2002/12/04 18:38:27 drochner Exp $
#

DISTNAME=	gnuplot-py-1.6
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
