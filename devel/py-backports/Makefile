# $NetBSD: Makefile,v 1.4 2021/11/08 12:00:18 adam Exp $

PKGNAME=	${PYPKGPREFIX}-backports-1.0
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/backports
COMMENT=	Namespace for backported Python features
LICENSE=	python-software-foundation

PY_PATCHPLIST=	yes

.include "../../lang/python/pyversion.mk"

INSTALLATION_DIRS+=	${PYSITELIB}/backports
.if ${_PYTHON_VERSION} != 27
INSTALLATION_DIRS+=	${PYSITELIB}/backports/__pycache__
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/__init__.py ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${PY_COMPILE_ALL} . && ${PY_COMPILE_O_ALL} .

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/__init__.* ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/
.if ${_PYTHON_VERSION} != 27
	${INSTALL_SCRIPT} ${WRKSRC}/__pycache__/__init__.* \
		${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__pycache__/
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
