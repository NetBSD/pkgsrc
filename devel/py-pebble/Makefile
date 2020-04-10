# $NetBSD: Makefile,v 1.5 2020/04/10 08:54:47 adam Exp $

DISTNAME=	Pebble-4.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pebble/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/noxdafox/pebble
COMMENT=	Threading and multiprocessing eye-candy
LICENSE=	gnu-lgpl-v3

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/test && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
