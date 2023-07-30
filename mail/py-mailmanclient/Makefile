# $NetBSD: Makefile,v 1.2 2023/07/30 15:32:49 adam Exp $

DISTNAME=	mailmanclient-3.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailmanclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Official Python bindings for the GNU Mailman 3 REST API
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
