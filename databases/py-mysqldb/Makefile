# $NetBSD: Makefile,v 1.10 2003/04/13 14:28:53 cjep Exp $

DISTNAME=	MySQL-python-0.9.2
PKGNAME=	${PYPKGPREFIX}-mysqldb-0.9.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL interface for Python

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

post-patch:
	${SED} -e "s|@MYSQLPREFIX@|${BUILDLINK_PREFIX.mysql-client}|" \
		-e "s|@MYSQLRTPREFIX@|${BUILDLINK_PREFIX.mysql-client}|" \
		<${WRKSRC}/setup.py >${WRKSRC}/setup.py.tmp
	${MV} ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
