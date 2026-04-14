# $NetBSD: Makefile,v 1.24 2026/04/14 13:57:22 adam Exp $

DISTNAME=	xandikos-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xandikos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xandikos.org/
COMMENT=	Lightweight CalDAV/CardDAV server
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-dulwich>=0.25.0:../../devel/py-dulwich
DEPENDS+=	${PYPKGPREFIX}-icalendar>=5.0.4:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-multidict-[0-9]*:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	xandikos

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
