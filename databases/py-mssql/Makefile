# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:20 joerg Exp $
#

DISTNAME=		pymssql-0.8.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		databases python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pymssql/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://pymssql.sourceforge.net/
COMMENT=		Python interface to MS SQL

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.freetds+=	freetds>=0.63

PYTHON_VERSIONS_ACCEPTED=	25 24
PYBINMODULE=		yes
PYDISTUTILSPKG=		yes

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
