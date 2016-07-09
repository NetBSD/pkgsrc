# $NetBSD: Makefile,v 1.12 2016/07/09 13:03:42 wiz Exp $

DISTNAME=	logilab-astng-0.24.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/logilab-astng/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.logilab.org/project/logilab-astng
COMMENT=	Extend Python abstract syntax tree
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-logilab-common>=0.53.0:../../devel/py-logilab-common

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-mxDateTime via py-logilab-common

do-test:
	cd ${WRKSRC} && ${SH} test/fulltest.sh ${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
