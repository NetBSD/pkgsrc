# $NetBSD: Makefile,v 1.8 2006/02/05 23:09:38 joerg Exp $
#

DISTNAME=	gnuplot-py-1.7
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.7
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
