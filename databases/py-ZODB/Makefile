# $NetBSD: Makefile,v 1.3 2004/02/24 15:29:40 wiz Exp $
#

DISTNAME=		ZODB3-3.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/3-/-/}
CATEGORIES=		databases
MASTER_SITES=		http://zope.org/Products/ZODB3.2/3.2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://zope.org/Products/ZODB3.2/3.2/
COMMENT=		Standalone distro of Zope Object Database

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 23 22pth 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
