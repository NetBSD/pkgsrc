# $NetBSD: Makefile,v 1.1 2017/03/07 18:15:21 minskim Exp $

DISTNAME=	requests-ftp-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-ftp/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/Lukasa/requests-ftp
COMMENT=	FTP transport adapter for use with the requests Python lib
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-requests>=1.0.0:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
