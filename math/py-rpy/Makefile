# $NetBSD: Makefile,v 1.29 2011/09/14 17:19:18 hans Exp $
#

DISTNAME=	rpy2-2.1.3
PKGNAME=	${PYPKGPREFIX}-rpy-2.1.3
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python
LICENSE=	mpl-1.1 OR gnu-gpl-v2 OR gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		YES
USE_LANGUAGES+=		c fortran77

BUILDLINK_API_DEPENDS.R+= R>=2.11.0

LDFLAGS.SunOS+=		-mimpure-text

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
