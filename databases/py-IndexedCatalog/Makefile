# $NetBSD: Makefile,v 1.7 2006/05/28 14:26:34 joerg Exp $
#

DISTNAME=		IndexedCatalog-0.6.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases python
MASTER_SITES=		http://async.com.br/projects/IndexedCatalog/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://async.com.br/projects/IndexedCatalog/
COMMENT=		Indexed Catalog extension for standalone ZODB

PYTHON_VERSIONS_ACCEPTED=	23 22

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes

.include "../../lang/python/extension.mk"
.include "../../databases/py-ZODB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
