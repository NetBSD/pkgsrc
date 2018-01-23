# $NetBSD: Makefile,v 1.1 2018/01/23 09:48:23 fhajny Exp $

DISTNAME=	PyNamecheap-0.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//:tl}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNamecheap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Bemmu/PyNamecheap/
COMMENT=	Namecheap API client in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
