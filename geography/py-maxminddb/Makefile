# $NetBSD: Makefile,v 1.2 2022/08/24 11:09:33 wiz Exp $

DISTNAME=	maxminddb-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maxminddb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/maxminddb/
COMMENT=	Reader for the MaxMind DB format
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
