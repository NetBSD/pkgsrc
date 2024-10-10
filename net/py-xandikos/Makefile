# $NetBSD: Makefile,v 1.16 2024/10/10 07:21:39 adam Exp $

DISTNAME=	xandikos-0.2.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xandikos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xandikos.org/
COMMENT=	Lightweight CalDAV/CardDAV server
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.21.6:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-icalendar>=5.0.4:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-multidict-[0-9]*:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} xandikos xandikos-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
