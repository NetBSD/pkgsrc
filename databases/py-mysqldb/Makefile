# $NetBSD: Makefile,v 1.40 2014/05/09 07:36:57 wiz Exp $

DISTNAME=	MySQL-python-1.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/MySQL-python/mysqldb/}
CATEGORIES=	databases python
MASTER_SITES=	http://pypi.python.org/packages/source/M/MySQL-python/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/farcepest/MySQLdb1/
COMMENT=	MySQL interface for Python
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.2.5

EGG_NAME=		${DISTNAME:S/MySQL-/MySQL_/}
USE_LANGUAGES=		c

# These files must not be world-writable.
pre-configure:
	${CHMOD} go-w ${WRKSRC}/MySQL_python.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
