# $NetBSD: Makefile,v 1.3 2015/04/01 02:16:26 rodent Exp $

DISTNAME=	PyMySQL-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	databases python
MASTER_SITES=	https://pypi.python.org/packages/source/P/PyMySQL/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/PyMySQL/PyMySQL/
COMMENT=	Pure-Python MySQL driver
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	26

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	pymysql/tests/thirdparty/test_MySQLdb/capabilities.py
REPLACE_PYTHON+=	pymysql/tests/thirdparty/test_MySQLdb/dbapi20.py
REPLACE_PYTHON+=	pymysql/tests/thirdparty/test_MySQLdb/test_MySQLdb_capabilities.py
REPLACE_PYTHON+=	pymysql/tests/thirdparty/test_MySQLdb/test_MySQLdb_dbapi20.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
