# $NetBSD: Makefile,v 1.3 2019/01/02 12:29:09 adam Exp $

DISTNAME=	requests-ftp-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-ftp/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/Lukasa/requests-ftp
COMMENT=	FTP transport adapter for use with the requests Python lib
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=1.0.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
