# $NetBSD: Makefile,v 1.5 2022/09/11 18:10:03 wiz Exp $

DISTNAME=	tubes-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=twisted/}
GITHUB_PROJECT=	tubes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twisted/tubes/
COMMENT=	Data-processing and flow-control engine for event-driven programs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-characteristic-[0-9]*:../../devel/py-characteristic
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

EGG_NAME=	Tubes-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
