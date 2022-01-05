# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:22 wiz Exp $

DISTNAME=	py-cpuinfo-8.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
PKGREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-cpuinfo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/workhorsy/py-cpuinfo
COMMENT=	Get CPU info with pure Python
LICENSE=	mit

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cpuinfo cpuinfo-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
