# $NetBSD: Makefile,v 1.10 2006/06/02 23:37:24 joerg Exp $
#

DISTNAME=	gnuplot-py-1.7
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.7
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
