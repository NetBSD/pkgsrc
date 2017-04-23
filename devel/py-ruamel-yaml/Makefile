# $NetBSD: Makefile,v 1.3 2017/04/23 15:52:33 leot Exp $

DISTNAME=	ruamel.yaml-0.14.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./-/1}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://bitbucket.org/ruamel/yaml
COMMENT=	YAML parser/emitter
LICENSE=	mit

PLIST_VARS+=	pyreq

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 30
DEPENDS+=	${PYPKGPREFIX}-ruamel-ordereddict>=0.4.9:../../devel/py-ruamel-ordereddict
PLIST.pyreq=	yes
.endif
.if ${_PYTHON_VERSION} < 35
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
PLIST.pyreq=	yes
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
