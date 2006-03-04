# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:10 jlam Exp $
#

DISTNAME=		IndexedCatalog-0.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases python
MASTER_SITES=		http://async.com.br/projects/IndexedCatalog/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://async.com.br/projects/IndexedCatalog/
COMMENT=		Indexed Catalog extension for standalone ZODB

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes

.include "../../lang/python/extension.mk"
.include "../../databases/py-ZODB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
