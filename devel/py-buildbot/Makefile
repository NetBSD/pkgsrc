# $NetBSD: Makefile,v 1.16 2017/12/18 12:13:55 adam Exp $

DISTNAME=	buildbot-0.9.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Continuous integration system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.16.0:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-JWT-[0-9]*:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.8.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-migrate>=0.9:../../databases/py-sqlalchemy-migrate
DEPENDS+=	${PYPKGPREFIX}-twisted>=14.0.1:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-txaio>=2.2.2:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.1.1:../../devel/py-ZopeInterface
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-jade-[0-9]*:../../textproc/py-jade
BUILD_DEPENDS+=	${PYPKGPREFIX}-lz4-[0-9]*:../../archivers/py-lz4
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-moto-[0-9]*:../../net/py-moto
BUILD_DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
BUILD_DEPENDS+=	${PYPKGPREFIX}-ramlfications-[0-9]*:../../textproc/py-ramlfications
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
BUILD_DEPENDS+=	${PYPKGPREFIX}-treq-[0-9]*:../../devel/py-treq
BUILD_DEPENDS+=	${PYPKGPREFIX}-txgithub-[0-9]*:../../devel/py-txgithub
BUILD_DEPENDS+=	${PYPKGPREFIX}-txrequests-[0-9]*:../../devel/py-txrequests

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} buildbot buildbot${PYVERSSUFFIX} && \
	${MV} buildbot_windows_service buildbot_windows_service${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"

.if "${PYPKGPREFIX}" == "py27" || "${PYPKGPREFIX}" == "py34"
BUILD_DEPENDS+=	${PYPKGPREFIX}-scandir-[0-9]*:../../devel/py-scandir
.endif

.include "../../mk/bsd.pkg.mk"
