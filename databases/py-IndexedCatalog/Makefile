# $NetBSD: Makefile,v 1.1.1.1 2004/02/26 22:53:29 minskim Exp $
#

DISTNAME=		IndexedCatalog-0.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		http://async.com.br/projects/IndexedCatalog/dist/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://async.com.br/projects/IndexedCatalog/
COMMENT=		Indexed Catalog extension for standalone ZODB

USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes
PYBINMODULE=		yes

.include "../../lang/python/extension.mk"
.include "../../databases/py-ZODB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
