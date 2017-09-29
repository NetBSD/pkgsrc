# $NetBSD: Makefile,v 1.1 2017/09/29 14:16:20 joerg Exp $

DISTNAME=	treq-17.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PYPI:=t/treq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twisted/treq
COMMENT=	HTTP library for Twisted
LICENSE=	mit

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0<3.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-twisted>=16.4.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-incremental-[0-9]*:../../devel/py-incremental

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
