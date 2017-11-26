# $NetBSD: Makefile,v 1.1 2017/11/26 17:10:16 adam Exp $

DISTNAME=	exam-0.10.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/exam/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fluxx/exam
COMMENT=	Helpers for better testing
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
