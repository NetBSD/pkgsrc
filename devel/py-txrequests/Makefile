# $NetBSD: Makefile,v 1.4 2022/02/13 08:53:44 wiz Exp $

DISTNAME=	txrequests-0.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txrequests/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tardyp/txrequests
COMMENT=	Asynchronous Python HTTP Requests for Humans
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.0:../../devel/py-requests

PYTHON_VERSIONED_DEPENDENCIES+=	twisted

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
