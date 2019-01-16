# $NetBSD: Makefile,v 1.1 2019/01/16 08:30:15 adam Exp $

DISTNAME=	pysendfile-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysendfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/pysendfile
COMMENT=	Python interface to sendfile(2)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
