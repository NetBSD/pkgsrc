# $NetBSD: Makefile,v 1.4 2022/07/08 14:23:38 wiz Exp $

DISTNAME=	PyNamecheap-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//:tl}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNamecheap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Bemmu/PyNamecheap/
COMMENT=	Namecheap API client in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
