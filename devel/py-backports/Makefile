# $NetBSD: Makefile,v 1.3 2019/12/13 09:08:01 adam Exp $

PKGNAME=	${PYPKGPREFIX}-backports-1.0
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/backports
COMMENT=	Namespace for backported Python features
LICENSE=	python-software-foundation

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS+=	${PYSITELIB}/backports

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/__init__.py ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${PY_COMPILE_ALL} . && ${PY_COMPILE_O_ALL} .

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/__init__.* ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
