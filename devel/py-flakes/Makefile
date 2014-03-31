# $NetBSD: Makefile,v 1.3 2014/03/31 08:30:53 wiz Exp $

DISTNAME=	pyflakes-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyflakes/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpad.net/pyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	mit

USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pyflakes ${DESTDIR}${PREFIX}/bin/pyflakes${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
