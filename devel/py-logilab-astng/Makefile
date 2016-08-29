# $NetBSD: Makefile,v 1.13 2016/08/29 15:44:26 darcy Exp $

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

do-test:
	cd ${WRKSRC} && ${SH} test/fulltest.sh ${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
