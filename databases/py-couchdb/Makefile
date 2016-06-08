# $NetBSD: Makefile,v 1.4 2016/06/08 17:43:22 wiz Exp $
#

DISTNAME=	CouchDB-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/CouchDB/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/couchdb-python/
COMMENT=	Couchdb python library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0.9:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.5.0:../../www/py-httplib2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/py-couchdb

REPLACE_PYTHON+=	couchdb/http.py couchdb/json.py
REPLACE_PYTHON+=	couchdb/tests/couch_tests.py couchdb/tools/dump.py
REPLACE_PYTHON+=	couchdb/tools/load.py couchdb/tools/replicate.py
REPLACE_PYTHON+=	couchdb/tools/replication_helper.py
REPLACE_PYTHON+=	couchdb/tools/replication_helper_test.py
REPLACE_PYTHON+=	couchdb/view.py
PY_PATCHPLIST=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.rst \
		${DESTDIR}${PREFIX}/share/doc/py-couchdb
	${MV} ${DESTDIR}${PREFIX}/bin/couchdb-dump \
		${DESTDIR}${PREFIX}/bin/couchdb-dump${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/couchdb-load \
		${DESTDIR}${PREFIX}/bin/couchdb-load${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/couchdb-replicate \
		${DESTDIR}${PREFIX}/bin/couchdb-replicate${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/couchpy \
		${DESTDIR}${PREFIX}/bin/couchpy${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
