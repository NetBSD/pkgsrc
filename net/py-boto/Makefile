# $NetBSD: Makefile,v 1.28 2017/05/26 04:26:22 adam Exp $

DISTNAME=	boto-2.47.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto/
COMMENT=	Python interface to Amazon web services
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-filechunkio-[0-9]*:../../devel/py-filechunkio

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

REPLACE_PYTHON+=	bin/*
REPLACE_PYTHON+=	boto/pyami/launch_ami.py
REPLACE_PYTHON+=	boto/services/bs.py
REPLACE_PYTHON+=	boto/services/result.py

PY_PATCHPLIST=			yes

post-install:
.for f in asadmin bundle_image cfadmin cq cwutil dynamodb_dump dynamodb_load \
	elbadmin fetch_file glacier instance_events kill_instance \
	launch_instance list_instances lss3 mturk pyami_sendmail route53 \
	s3put sdbadmin taskadmin
	${MV} ${DESTDIR}${PREFIX}/bin/${f} \
		${DESTDIR}${PREFIX}/bin/${f}${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
