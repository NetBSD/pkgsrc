# $NetBSD: Makefile,v 1.26 2020/01/18 23:32:18 rillig Exp $

DISTNAME=	gnuplot-py-1.8
PKGNAME=	${PYPKGPREFIX}-gnuplot-1.8
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnuplot-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gnuplot-py.sourceforge.net/
COMMENT=	Python package that interfaces to gnuplot
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.8

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
