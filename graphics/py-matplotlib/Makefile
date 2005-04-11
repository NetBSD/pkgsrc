# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:08 tv Exp $
#

DISTNAME=		matplotlib-0.32
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Matlab-style plotting package for Python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

DEPENDS+=		${PYPKGPREFIX}-Numeric>=23.1:../../math/py-Numeric

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
