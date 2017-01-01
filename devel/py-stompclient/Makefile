# $NetBSD: Makefile,v 1.11 2017/01/01 14:43:35 wiz Exp $

DISTNAME=	stompclient-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stompclient/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/stompclient
COMMENT=	Lightweight and extensible STOMP messaging client
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
