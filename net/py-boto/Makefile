# $NetBSD: Makefile,v 1.22 2014/06/09 00:49:33 rodent Exp $

DISTNAME=	boto-2.29.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python www
MASTER_SITES=	https://pypi.python.org/packages/source/b/boto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto/
COMMENT=	Python interface to Amazon web services
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-filechunkio-[0-9]*:../../devel/py-filechunkio

REPLACE_PYTHON+=	bin/* boto/pyami/launch_ami.py boto/services/bs.py
REPLACE_PYTHON+=	boto/services/result.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-filechunkio
PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/asadmin \
		${DESTDIR}${PREFIX}/bin/asadmin${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/bundle_image \
		${DESTDIR}${PREFIX}/bin/bundle_image${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/cfadmin \
		${DESTDIR}${PREFIX}/bin/cfadmin${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/cq \
		${DESTDIR}${PREFIX}/bin/cq${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/cwutil \
		${DESTDIR}${PREFIX}/bin/cwutil${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/dynamodb_dump \
		${DESTDIR}${PREFIX}/bin/dynamodb_dump${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/dynamodb_load \
		${DESTDIR}${PREFIX}/bin/dynamodb_load${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/elbadmin \
		${DESTDIR}${PREFIX}/bin/elbadmin${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/fetch_file \
		${DESTDIR}${PREFIX}/bin/fetch_file${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/glacier \
		${DESTDIR}${PREFIX}/bin/glacier${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/instance_events \
		${DESTDIR}${PREFIX}/bin/instance_events${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/kill_instance \
		${DESTDIR}${PREFIX}/bin/kill_instance${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/launch_instance \
		${DESTDIR}${PREFIX}/bin/launch_instance${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/list_instances \
		${DESTDIR}${PREFIX}/bin/list_instances${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/lss3 \
		${DESTDIR}${PREFIX}/bin/lss3${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/mturk \
		${DESTDIR}${PREFIX}/bin/mturk${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/pyami_sendmail \
		${DESTDIR}${PREFIX}/bin/pyami_sendmail${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/route53 \
		${DESTDIR}${PREFIX}/bin/route53${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/s3put \
		${DESTDIR}${PREFIX}/bin/s3put${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/sdbadmin \
		${DESTDIR}${PREFIX}/bin/sdbadmin${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/taskadmin \
		${DESTDIR}${PREFIX}/bin/taskadmin${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
