# $NetBSD: Makefile,v 1.16 2025/02/23 11:47:13 wiz Exp $

DISTNAME=	setproctitle-1.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setproctitle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dvarrazzo/py-setproctitle
COMMENT=	Python module to customize the process title
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

# test status as of 1.3.5
# 8 failed, 16 passed, 4 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
