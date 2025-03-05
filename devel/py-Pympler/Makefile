# $NetBSD: Makefile,v 1.9 2025/03/05 09:36:18 wiz Exp $

DISTNAME=	pympler-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^p/P/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pympler/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pympler/pympler
COMMENT=	Python memory analysis tool
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-bottle-[0-9]*:../../www/py-bottle

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
