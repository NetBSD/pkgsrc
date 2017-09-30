# $NetBSD: Makefile,v 1.14 2017/09/30 07:22:37 wiz Exp $

DISTNAME=	buildbot-0.9.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Continuous integration system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=0.8.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-migrate>=0.9:../../databases/py-sqlalchemy-migrate
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-txaio>=2.2.2:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-twisted>=14.0.1:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-JWT-[0-9]*:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.16.0:../../www/py-autobahn

# Self-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-lz4-[0-9]*:../../archivers/py-lz4
BUILD_DEPENDS+=	${PYPKGPREFIX}-buildbot-worker-[0-9]*:../../devel/py-buildbot-worker
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
BUILD_DEPENDS+=	${PYPKGPREFIX}-ramlfications-[0-9]*:../../textproc/py-ramlfications
BUILD_DEPENDS+=	${PYPKGPREFIX}-treq-[0-9]*:../../devel/py-treq
BUILD_DEPENDS+=	${PYPKGPREFIX}-txgithub-[0-9]*:../../devel/py-txgithub
BUILD_DEPENDS+=	${PYPKGPREFIX}-txrequests-[0-9]*:../../devel/py-txrequests
BUILD_DEPENDS+=	${PYPKGPREFIX}-pathlib2-[0-9]*:../../devel/py-pathlib2
BUILD_DEPENDS+=	${PYPKGPREFIX}-moto-[0-9]*:../../net/py-moto

.include "../../lang/python/egg.mk"

.if "${PYPKGPREFIX}" == "py27" || "${PYPKGPREFIX}" == "py34"
BUILD_DEPENDS+=	${PYPKGPREFIX}-scandir-[0-9]*:../../devel/py-scandir
.endif

.include "../../mk/bsd.pkg.mk"
