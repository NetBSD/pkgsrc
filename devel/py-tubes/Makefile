# $NetBSD: Makefile,v 1.4 2022/02/13 09:44:10 wiz Exp $

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

PYTHON_VERSIONED_DEPENDENCIES+=	twisted

USE_LANGUAGES=	# none

EGG_NAME=	Tubes-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
