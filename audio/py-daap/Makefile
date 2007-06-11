# $NetBSD: Makefile,v 1.2 2007/06/11 17:38:35 joerg Exp $
#

DISTNAME=	PythonDaap-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	http://jerakeen.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jerakeen.org/PythonDaap/
COMMENT=	Python binding for DAAP

PYTHON_VERSIONS_ACCEPTED=	24 23

PYSETUP=		setup.py
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} install

.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
