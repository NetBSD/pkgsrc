# $NetBSD: Makefile,v 1.1 2020/10/08 18:31:24 khorben Exp $

DISTNAME=	bump2version-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/29/2a/688aca6eeebfe8941235be53f4da780c6edee05dbbea5d7abaa3aab6fad2/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/c4urself/bump2version
COMMENT=	Version-bump software with a single command
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	37 36

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/bumpversion ${DESTDIR}${PREFIX}/bin/bumpversion-${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/bump2version ${DESTDIR}${PREFIX}/bin/bump2version-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
