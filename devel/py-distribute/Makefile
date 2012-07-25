# $NetBSD: Makefile,v 1.1 2012/07/25 19:05:51 drochner Exp $
#

DISTNAME=	distribute-0.6.28
PKGNAME=	${PYPKGPREFIX}-distribute-0.6.28
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
