# $NetBSD: Makefile,v 1.10 2020/07/27 17:30:29 adam Exp $

DISTNAME=	xandikos-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xandikos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jelmer.uk/code/xandikos/
COMMENT=	Lightweight CalDAV/CardDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.19.1:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-icalendar-[0-9]*:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-multidict-[0-9]*:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-prometheus_client-[0-9]*:../../net/py-prometheus_client

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} xandikos xandikos-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
