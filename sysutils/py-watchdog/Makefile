# $NetBSD: Makefile,v 1.2 2016/06/01 12:37:14 wiz Exp $

DISTNAME=	watchdog-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/watchdog/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/gorakhargosh/watchdog
COMMENT=	Filesystem events monitoring
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-argh>=0.24.1:../../devel/py-argh
DEPENDS+=	${PYPKGPREFIX}-pathtools>=0.1.1:../../sysutils/py-pathtools

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
