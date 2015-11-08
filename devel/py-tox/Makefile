# $NetBSD: Makefile,v 1.1 2015/11/08 09:21:52 wiz Exp $

DISTNAME=	tox-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tox.testrun.org/
COMMENT=	Virtualenv-based automation of test activities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
DEPENDS+=	${PYPKGPREFIX}-py>=1.4.17:../../devel/py-py
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.3.0:../../devel/py-pluggy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
