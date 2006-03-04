# $NetBSD: Makefile,v 1.14 2006/03/04 21:29:10 jlam Exp $
#

DISTNAME=		ZODB3-3.2.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/3-/-/}
PKGREVISION=		3
CATEGORIES=		databases python
MASTER_SITES=		http://zope.org/Products/ZODB3.2/3.2.1/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://zope.org/Products/ZODB3.2/3.2/
COMMENT=		Standalone distro of Zope Object Database

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
