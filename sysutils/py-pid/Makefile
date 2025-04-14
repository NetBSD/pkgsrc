# $NetBSD: Makefile,v 1.5 2025/04/14 08:31:30 adam Exp $

DISTNAME=	pid-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trbs/pid
COMMENT=	Pidfile featuring stale detection and file-locking
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.0:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
