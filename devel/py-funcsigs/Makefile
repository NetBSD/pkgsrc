# $NetBSD: Makefile,v 1.4 2016/06/08 17:49:20 wiz Exp $

DISTNAME=	funcsigs-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/funcsigs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/aliles/funcsigs/
COMMENT=	Python function signatures package for Python 2.6, 2.7 and 3.2+
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
