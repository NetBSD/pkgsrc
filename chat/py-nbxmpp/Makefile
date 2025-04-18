# $NetBSD: Makefile,v 1.14 2025/04/18 10:38:39 adam Exp $

DISTNAME=	nbxmpp-6.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbxmpp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.gajim.org/gajim/python-nbxmpp
COMMENT=	Asynchronous Python library for XMPP
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	libsoup3-[0-9]*:../../net/libsoup3
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.42.0:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-precis-i18n>=1.0.0:../../textproc/py-precis-i18n

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
