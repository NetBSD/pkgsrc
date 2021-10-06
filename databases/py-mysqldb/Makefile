# $NetBSD: Makefile,v 1.52 2021/10/06 18:00:12 tron Exp $

DISTNAME=	mysqlclient-1.3.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/mysqlclient/mysqldb/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mysqlclient/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/mysqlclient/1.3.10/
COMMENT=	MySQL interface for Python
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c

PYPKGVER=	${PYPKGPREFIX:S/py//}

post-install:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/MySQLdb/__pycache__ && \
	${RM} -f compat.cpython-${PYPKGVER}.opt-1.pyc \
	    compat.cpython-${PYPKGVER}.pyc

.include "../../lang/python/egg.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
