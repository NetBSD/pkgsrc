# $NetBSD: Makefile,v 1.16 2006/05/27 00:00:56 joerg Exp $
#

DISTNAME=		matplotlib-0.87.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Matlab-style plotting package for Python

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"

PYTHON_VERSIONS_ACCEPTED=	24 23 22

.if ${PYPACKAGE} == "python22" || ${PYPACKAGE} == "python23"
PLIST_SUBST+=		COND_SUBPROCESS=""
.else
PLIST_SUBST+=		COND_SUBPROCESS="@comment "
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
