# $NetBSD: Makefile,v 1.2 2012/10/20 16:11:00 wiz Exp $
#

DISTNAME=	distribute-0.6.29
PKGNAME=	${PYPKGPREFIX}-distribute-0.6.29
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/d/distribute/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/distribute
COMMENT=	Replacement for setuptools
LICENSE=	python-software-foundation # or ZPL

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS+=	${PYPKGPREFIX}-setuptools-[0-9]*
PYTHON_VERSIONS_INCLUDE_3X= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
