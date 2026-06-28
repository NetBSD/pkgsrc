# $NetBSD: Makefile,v 1.7 2026/06/28 15:41:27 wiz Exp $

DISTNAME=	mailman-hyperkitty-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailman-hyperkitty/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Mailman archiver plugin for HyperKitty
LICENSE=	gnu-lgpl-v3

BROKEN=		"Depends on BROKEN mailman3"

DEPENDS+=	${PYPKGPREFIX}-mailman>=3.0.0:../../mail/mailman3
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	312

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
