# $NetBSD: Makefile,v 1.23 2008/04/25 19:47:58 joerg Exp $

DISTNAME=	MySQL-python-0.9.2
PKGNAME=	${PYPKGPREFIX}-mysqldb-0.9.2
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL interface for Python

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

PYTHON_VERSIONS_ACCEPTED=	25 24 23 21

.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/python/extension.mk"

# To pickup python version info
pre-configure:
	${SED} -e "s|@MYSQLPREFIX@|${BUILDLINK_PREFIX.mysql-client}|" \
		-e "s|@MYSQLRTPREFIX@|${BUILDLINK_PREFIX.mysql-client}|" \
		<${WRKSRC}/setup.py >${WRKSRC}/setup.py.tmp
.if ${PYPKGPREFIX:Mpy20} == "py20"
	${SED} -e "s|platforms = .ALL.|#platforms = \"ALL\"|" <${WRKSRC}/setup.py.tmp > ${WRKSRC}/setup.py.tmp2
	${MV} ${WRKSRC}/setup.py.tmp2 ${WRKSRC}/setup.py.tmp
.endif
	${MV} ${WRKSRC}/setup.py.tmp ${WRKSRC}/setup.py

.include "../../mk/bsd.pkg.mk"
