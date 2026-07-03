# $NetBSD: Makefile,v 1.16 2026/07/03 12:13:50 adam Exp $

DISTNAME=	treq-26.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/treq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twisted/treq
COMMENT=	HTTP library for Twisted
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-hyperlink>=21.0.0:../../www/py-hyperlink
DEPENDS+=	${PYPKGPREFIX}-incremental>=24.7.2:../../devel/py-incremental
DEPENDS+=	${PYPKGPREFIX}-multipart>=0:../../www/py-multipart
DEPENDS+=	${PYPKGPREFIX}-twisted>=22.10.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-httpbin>=0.7.0:../../www/py-httpbin
TEST_DEPENDS+=	${PYPKGPREFIX}-werkzeug>=2.0.3:../../www/py-werkzeug

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
