# $NetBSD: Makefile,v 1.3 2016/05/04 14:02:18 wiz Exp $

DISTNAME=	funcsigs-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/94/4a/db842e7a0545de1cdb0439bb80e6e42dfe82aaeaadd4072f2263a4fbed23/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/aliles/funcsigs/
COMMENT=	Python function signatures package for Python 2.6, 2.7 and 3.2+
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
