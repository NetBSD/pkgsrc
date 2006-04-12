# $NetBSD: Makefile,v 1.12 2006/04/12 22:57:59 joerg Exp $
#

DISTNAME=		matplotlib-0.87.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Matlab-style plotting package for Python

USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
