# $NetBSD: Makefile,v 1.5 2016/06/08 17:43:22 wiz Exp $

DISTNAME=	PyMySQL-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyMySQL/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/PyMySQL/PyMySQL/
COMMENT=	Pure-Python MySQL driver
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	pymysql/tests/thirdparty/test_MySQLdb/capabilities.py
REPLACE_PYTHON+=	pymysql/tests/thirdparty/test_MySQLdb/dbapi20.py
REPLACE_PYTHON+=	pymysql/tests/thirdparty/test_MySQLdb/test_MySQLdb_capabilities.py
REPLACE_PYTHON+=	pymysql/tests/thirdparty/test_MySQLdb/test_MySQLdb_dbapi20.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
