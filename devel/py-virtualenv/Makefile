# $NetBSD: Makefile,v 1.1 2012/10/06 22:23:22 wiz Exp $

DISTNAME=	virtualenv-1.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/v/virtualenv/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/virtualenv
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	virtualenv.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
