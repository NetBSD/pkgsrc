# $NetBSD: Makefile,v 1.1 2020/03/16 14:16:43 wiz Exp $

DISTNAME=	googleapis-common-protos-1.51.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/googleapis-common-protos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/googleapis
COMMENT=	Python support for Public interface definitions of Google APIs
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.6.0:../../devel/py-protobuf

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
