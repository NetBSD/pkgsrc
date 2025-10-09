# $NetBSD: Makefile,v 1.7 2025/10/09 07:57:34 wiz Exp $

DISTNAME=	mixbox-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mixbox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CybOXProject/mixbox
COMMENT=	Utility library for cybox, maec, and stix packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-ordered-set-[0-9]*:../../devel/py-ordered-set

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
