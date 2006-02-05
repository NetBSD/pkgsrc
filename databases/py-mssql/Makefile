# $NetBSD: Makefile,v 1.2 2006/02/05 23:08:36 joerg Exp $
#

DISTNAME=		pymssql-0.7.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		1
CATEGORIES=		databases python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pymssql/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://pymssql.sourceforge.net/
COMMENT=		Python interface to MS SQL

BUILDLINK_DEPENDS.freetds+=	freetds>=0.63

PYTHON_VERSION_REQD=	24
PYBINMODULE=		yes
PYDISTUTILSPKG=		yes

.include "../../databases/freetds/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
