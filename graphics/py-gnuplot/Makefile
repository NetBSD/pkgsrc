# $NetBSD: Makefile,v 1.29 2020/10/12 21:52:01 bacon Exp $

DISTNAME=	gnuplot-py-1.8
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.8
PKGREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.8

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
