# $NetBSD: Makefile,v 1.3 2008/04/25 20:39:06 joerg Exp $
#

DISTNAME=	PythonDaap-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	http://jerakeen.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jerakeen.org/PythonDaap/
COMMENT=	Python binding for DAAP

PYSETUP=		setup.py
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} install

.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
