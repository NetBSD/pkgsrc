# $NetBSD: Makefile,v 1.10 2017/02/13 11:08:25 wen Exp $

DISTNAME=	pyflakes-1.5.0
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
