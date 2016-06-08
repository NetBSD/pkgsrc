# $NetBSD: Makefile,v 1.9 2016/06/08 17:43:26 wiz Exp $

VERS=		0.9.3
DISTNAME=	rope-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rope/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://rope.sourceforge.net/
COMMENT=	Rope is a python refactoring library
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

# XXX tests in contrib.codeassisttest fail
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
