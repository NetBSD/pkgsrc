# $NetBSD: Makefile,v 1.10 2022/01/05 15:41:06 wiz Exp $

DISTNAME=	memory_profiler-0.60.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/memory_profiler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pythonprofilers/memory_profiler
COMMENT=	Monitors memory usage of a Python program
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-matplotlib

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mprof mprof-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
