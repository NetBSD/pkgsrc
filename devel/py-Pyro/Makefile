# $NetBSD: Makefile,v 1.1.1.1 2004/12/31 10:13:56 darcy Exp $
#

DISTNAME=		Pyro-3.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pyro/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pyro.sourceforge.net/
COMMENT=		Distributed Object Technology system in Python

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
