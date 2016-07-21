# $NetBSD: Makefile,v 1.16 2016/07/21 12:13:12 wiz Exp $

DISTNAME=	ipython-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.0.1:../../net/py-zmq

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

REPLACE_PYTHON=	*/*/*.py */*/*/*.py

post-install:
	mv ${DESTDIR}${PREFIX}/bin/iptest ${DESTDIR}${PREFIX}/bin/iptest${PYVERSSUFFIX}
	for f in ipcluster ipcontroller ipengine ipython ; \
	do \
		mv ${DESTDIR}${PREFIX}/bin/$$f ${DESTDIR}${PREFIX}/bin/$${f}${PYVERSSUFFIX}; \
		mv ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$${f}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$${f}${PYVERSSUFFIX}.1; \
	done

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
