# $NetBSD: Makefile,v 1.5 2004/02/25 21:24:44 minskim Exp $
#

DISTNAME=		ZODB3-3.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/3-/-/}
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://zope.org/Products/ZODB3.2/3.2/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://zope.org/Products/ZODB3.2/3.2/
COMMENT=		Standalone distro of Zope Object Database

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth 23 22pth 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
