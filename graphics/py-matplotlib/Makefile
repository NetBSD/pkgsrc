# $NetBSD: Makefile,v 1.1.1.1 2004/02/21 01:39:48 minskim Exp $
#

DISTNAME=		matplotlib-0.32
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Matlab-style plotting package for Python

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Numeric>=23.1:../../math/py-Numeric

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
