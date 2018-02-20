# $NetBSD: Makefile,v 1.2 2018/02/20 10:18:40 hauke Exp $

PKGNAME=	${PYPKGPREFIX}-backports-1.0
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/backports
COMMENT=	Namespace for backported Python features
LICENSE=	python-software-foundation

WRKSRC=		${WRKDIR}/bp
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS+=	${PYSITELIB}/backports

do-extract:
	mkdir ${WRKDIR}/bp
	${CP} ${FILESDIR}/__init__.py ${WRKSRC}

do-build:
	cd ${WRKSRC}; ${PYTHONBIN} -m compileall .; ${PYTHONBIN} -O -m compileall .

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/__init__.* ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
