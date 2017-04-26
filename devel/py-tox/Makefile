# $NetBSD: Makefile,v 1.2 2017/04/26 13:25:29 fhajny Exp $

DISTNAME=	tox-2.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tox.testrun.org/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-virtualenv>=1.11.2:../../devel/py-virtualenv
DEPENDS+=	${PYPKGPREFIX}-py>=1.4.17:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.3.0<1.0:../../devel/py-pluggy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
