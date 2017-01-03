# $NetBSD: Makefile,v 1.9 2017/01/03 13:23:03 jperkin Exp $

DISTNAME=	pythonz-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	https://github.com/saghul/pythonz/archive/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/saghul/pythonz/
COMMENT=	Installation manager supporting CPython, Stackless, PyPy and Jython
LICENSE=	mit

WRKSRC=		${WRKDIR}/pythonz-${DISTNAME}
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.2.1

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pythonz \
		${DESTDIR}${PREFIX}/bin/pythonz${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/pythonz_install \
		${DESTDIR}${PREFIX}/bin/pythonz_install${PYVERSSUFFIX} || ${TRUE}
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PYSITELIB}/pythonz/patches/osx/python25/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
