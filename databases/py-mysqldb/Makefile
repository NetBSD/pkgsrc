# $NetBSD: Makefile,v 1.15 2004/10/03 00:13:23 tv Exp $

DISTNAME=	MySQL-python-0.9.2
PKGNAME=	${PYPKGPREFIX}-mysqldb-0.9.2
PKGREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mysql-python/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mysql-python
COMMENT=	MySQL interface for Python

USE_BUILDLINK3=	yes
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../databases/mysql-client/buildlink3.mk"
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
