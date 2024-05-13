# $NetBSD: Makefile,v 1.2 2024/05/13 13:56:29 jperkin Exp $

DISTNAME=	zulip-term-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zulip-term/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zulip/zulip-terminal
COMMENT=	Zulip's official terminal client
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.10.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.7.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.11.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.8.1:../../x11/py-pyperclip
DEPENDS+=	${PYPKGPREFIX}-pytz>=2022.1:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=2.1:../../time/py-tzlocal
DEPENDS+=	${PYPKGPREFIX}-urwid>=2.1.2:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-urwid_readline>=0.13:../../devel/py-urwid_readline
DEPENDS+=	${PYPKGPREFIX}-zulip>=0.8.2:../../chat/py-zulip
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
