# $NetBSD: Makefile,v 1.9 2017/01/03 13:23:02 jperkin Exp $

DISTNAME=	pyflakes-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyflakes/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpad.net/pyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	mit

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pyflakes ${DESTDIR}${PREFIX}/bin/pyflakes${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
