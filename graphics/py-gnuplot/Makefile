# $NetBSD: Makefile,v 1.3 2003/07/17 21:42:32 grant Exp $
#

DISTNAME=	gnuplot-py-1.6
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
