# $NetBSD: Makefile,v 1.8 2002/09/21 23:46:47 jlam Exp $

DISTNAME=	MySQL-python-0.9.1
PKGNAME=	${PYPKGPREFIX}-mysqldb-0.9.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL interface for Python

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

post-patch:
	${SED} -e "s|@MYSQLPREFIX@|${BUILDLINK_DIR}|" \
		-e "s|@MYSQLRTPREFIX@|${BUILDLINK_PREFIX.mysql-client}|" \
		<${WRKSRC}/setup.py >${WRKSRC}/setup.py.tmp
	${MV} ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

.include "../../databases/mysql-client/buildlink.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
