# $NetBSD: Makefile,v 1.6 2007/06/15 16:08:39 obache Exp $
#

DISTNAME=		pymssql-0.8.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		databases python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pymssql/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://pymssql.sourceforge.net/
COMMENT=		Python interface to MS SQL

BUILDLINK_API_DEPENDS.freetds+=	freetds>=0.63

PYTHON_VERSIONS_ACCEPTED=	24
PYBINMODULE=		yes
PYDISTUTILSPKG=		yes

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
