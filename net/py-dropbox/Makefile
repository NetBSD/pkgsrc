# $NetBSD: Makefile,v 1.11 2021/03/20 19:03:43 adam Exp $

DISTNAME=	dropbox-11.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dropbox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dropbox.com/developers
COMMENT=	Dropbox Python API
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.16.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stone>=2.0:../../net/py-stone

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
