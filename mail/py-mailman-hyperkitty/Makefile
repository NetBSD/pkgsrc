# $NetBSD: Makefile,v 1.3 2023/10/14 01:22:43 markd Exp $

DISTNAME=	mailman-hyperkitty-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailman-hyperkitty/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Mailman archiver plugin for HyperKitty
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-mailman>=3.0.0:../../mail/mailman3
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-zope.interface-[0-9]*:../../devel/py-zope.interface

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
