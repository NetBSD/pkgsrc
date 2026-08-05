# $NetBSD: Makefile,v 1.3 2026/08/05 02:51:06 adam Exp $

DISTNAME=	mailmanclient-3.3.5
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mailmanclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Official Python bindings for the GNU Mailman 3 REST API
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
