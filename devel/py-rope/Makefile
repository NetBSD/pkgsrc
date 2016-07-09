# $NetBSD: Makefile,v 1.10 2016/07/09 13:03:43 wiz Exp $

VERS=		0.9.3
DISTNAME=	rope-${VERS}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rope/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://rope.sourceforge.net/
COMMENT=	Rope is a python refactoring library
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35

# XXX tests in contrib.codeassisttest fail
do-test:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
