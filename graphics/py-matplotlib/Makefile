# $NetBSD: Makefile,v 1.2 2004/07/22 09:16:02 recht Exp $
#

DISTNAME=		matplotlib-0.32
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics python
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
