# $NetBSD: Makefile,v 1.11 2025/02/06 20:45:37 gdt Exp $

DISTNAME=	nbxmpp-4.4.0
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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
