# $NetBSD: Makefile,v 1.1 2026/10/24 10:47:18 adam Exp $

DISTNAME=	diagnostic-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/diagnostic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pradyunsg/diagnostic
COMMENT=	Present errors that contain causes better understand what happened
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-markdown-it-py>=0:../../textproc/py-markdown-it-py
DEPENDS+=	${PYPKGPREFIX}-rich>=0:../../comms/py-rich

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
