# $NetBSD: Makefile,v 1.4 2004/05/02 03:55:16 snj Exp $
#

DISTNAME=	gnuplot-py-1.6
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot

PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
