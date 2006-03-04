# $NetBSD: Makefile,v 1.9 2006/03/04 21:29:51 jlam Exp $
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

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
