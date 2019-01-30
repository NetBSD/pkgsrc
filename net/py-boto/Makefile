# $NetBSD: Makefile,v 1.33 2019/01/30 16:07:07 leot Exp $

DISTNAME=	boto-2.49.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	net python www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/boto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/boto/
COMMENT=	Python interface to Amazon web services
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-filechunkio-[0-9]*:../../devel/py-filechunkio
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

post-install:
.for f in asadmin bundle_image cfadmin cq cwutil dynamodb_dump dynamodb_load \
	elbadmin fetch_file glacier instance_events kill_instance \
	launch_instance list_instances lss3 mturk pyami_sendmail route53 \
	s3put sdbadmin taskadmin
	${MV} ${DESTDIR}${PREFIX}/bin/${f} \
		${DESTDIR}${PREFIX}/bin/${f}${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
