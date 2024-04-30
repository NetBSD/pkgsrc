# $NetBSD: Makefile,v 1.20 2024/04/30 13:22:13 wiz Exp $

DISTNAME=	irc-20.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/irc/irclib/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/irc/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://python-irclib.sourceforge.net/
COMMENT=	Internet Relay Chat (IRC) protocol client library
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-jaraco.collections>=0:../../devel/py-jaraco.collections
DEPENDS+=	${PYPKGPREFIX}-jaraco.text>=3.10:../../textproc/py-jaraco.text
DEPENDS+=	${PYPKGPREFIX}-jaraco.logging>=0:../../devel/py-jaraco.logging
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=1.20:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-jaraco.stream>=0:../../devel/py-jaraco.stream
DEPENDS+=	${PYPKGPREFIX}-pytz>=0:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=0:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-tempora>=1.6:../../time/py-tempora

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
