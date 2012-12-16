# $NetBSD: Makefile,v 1.4 2012/12/16 15:41:15 wiz Exp $
#

DISTNAME=	distribute-0.6.32
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/d/distribute/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/distribute
COMMENT=	Replacement for setuptools
LICENSE=	python-software-foundation # or ZPL

CONFLICTS+=	${PYPKGPREFIX}-setuptools-[0-9]*
PYTHON_VERSIONS_INCLUDE_3X= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
