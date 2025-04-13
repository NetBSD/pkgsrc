# $NetBSD: Makefile,v 1.21 2025/04/13 12:27:04 wiz Exp $

DISTNAME=	parso-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parso/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidhalter/parso
COMMENT=	Python Parser
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
