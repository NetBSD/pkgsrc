# $NetBSD: Makefile,v 1.5 2004/07/22 09:16:02 recht Exp $
#

DISTNAME=	gnuplot-py-1.6
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.6
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot

PYDISTUTILSPKG=	yes
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
