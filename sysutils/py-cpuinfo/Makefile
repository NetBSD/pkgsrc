# $NetBSD: Makefile,v 1.1 2020/05/18 12:22:49 wiz Exp $

DISTNAME=	py-cpuinfo-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-cpuinfo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/workhorsy/py-cpuinfo
COMMENT=	Get CPU info with pure Python
LICENSE=	mit

#PYTHON_VERSIONED_DEPENDENCIES+=	test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cpuinfo cpuinfo-${PYVERSSUFFIX} || ${TRUE}

#.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
