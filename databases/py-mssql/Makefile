# $NetBSD: Makefile,v 1.28 2019/04/26 13:13:47 maya Exp $

DISTNAME=		pymssql-1.0.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		7
CATEGORIES=		databases python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pymssql/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://pymssql.sourceforge.net/
COMMENT=		Python interface to MS SQL
LICENSE=		gnu-lgpl-v2.1

SUBST_CLASSES+=		crlf
SUBST_MESSAGE.crlf=	stripping EOL CR
SUBST_STAGE.crlf=	post-extract
SUBST_FILES.crlf=	mssqldbmodule.c pymssql.py
SUBST_FILTER_CMD.crlf=	${TR} -d '\r'

BUILDLINK_API_DEPENDS.freetds+=	freetds>=0.63

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 1.0.2; v2 might be better.

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
