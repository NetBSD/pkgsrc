# $NetBSD: Makefile,v 1.10 2024/08/06 23:21:25 gdt Exp $

DISTNAME=	nbxmpp-2.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbxmpp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.gajim.org/gajim/python-nbxmpp
COMMENT=	Asynchronous Python library for XMPP
LICENSE=	gnu-gpl-v3

DEPENDS+=	libsoup-[0-9]*:../../net/libsoup
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-precis-i18n>=1.0.0:../../textproc/py-precis-i18n

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
