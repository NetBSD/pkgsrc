# $NetBSD: Makefile,v 1.1.1.1 2012/01/23 21:39:32 pettai Exp $
#

DISTNAME=	pip-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c9:../../devel/py-setuptools

REPLACE_PYTHON=	${WRKSRC}/*.py

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=		PYVERSSUFFIX="${PYVERSSUFFIX}"

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
