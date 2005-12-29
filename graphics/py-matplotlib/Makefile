# $NetBSD: Makefile,v 1.6 2005/12/29 20:29:34 markd Exp $
#

DISTNAME=		matplotlib-0.83
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Matlab-style plotting package for Python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
