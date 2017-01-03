# $NetBSD: Makefile,v 1.26 2017/01/03 13:23:03 jperkin Exp $

DISTNAME=	boto-2.37.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto/
COMMENT=	Python interface to Amazon web services
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-filechunkio-[0-9]*:../../devel/py-filechunkio

REPLACE_PYTHON+=	bin/* boto/pyami/launch_ami.py boto/services/bs.py
REPLACE_PYTHON+=	boto/services/result.py

PY_PATCHPLIST=			yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/asadmin \
		${DESTDIR}${PREFIX}/bin/asadmin${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/bundle_image \
		${DESTDIR}${PREFIX}/bin/bundle_image${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/cfadmin \
		${DESTDIR}${PREFIX}/bin/cfadmin${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/cq \
		${DESTDIR}${PREFIX}/bin/cq${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/cwutil \
		${DESTDIR}${PREFIX}/bin/cwutil${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/dynamodb_dump \
		${DESTDIR}${PREFIX}/bin/dynamodb_dump${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/dynamodb_load \
		${DESTDIR}${PREFIX}/bin/dynamodb_load${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/elbadmin \
		${DESTDIR}${PREFIX}/bin/elbadmin${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/fetch_file \
		${DESTDIR}${PREFIX}/bin/fetch_file${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/glacier \
		${DESTDIR}${PREFIX}/bin/glacier${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/instance_events \
		${DESTDIR}${PREFIX}/bin/instance_events${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/kill_instance \
		${DESTDIR}${PREFIX}/bin/kill_instance${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/launch_instance \
		${DESTDIR}${PREFIX}/bin/launch_instance${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/list_instances \
		${DESTDIR}${PREFIX}/bin/list_instances${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/lss3 \
		${DESTDIR}${PREFIX}/bin/lss3${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/mturk \
		${DESTDIR}${PREFIX}/bin/mturk${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/pyami_sendmail \
		${DESTDIR}${PREFIX}/bin/pyami_sendmail${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/route53 \
		${DESTDIR}${PREFIX}/bin/route53${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/s3put \
		${DESTDIR}${PREFIX}/bin/s3put${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/sdbadmin \
		${DESTDIR}${PREFIX}/bin/sdbadmin${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/taskadmin \
		${DESTDIR}${PREFIX}/bin/taskadmin${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
