# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:35 joerg Exp $
#

DISTNAME=		IndexedCatalog-0.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases python
MASTER_SITES=		http://async.com.br/projects/IndexedCatalog/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://async.com.br/projects/IndexedCatalog/
COMMENT=		Indexed Catalog extension for standalone ZODB

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes

.include "../../lang/python/extension.mk"
.include "../../databases/py-ZODB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
