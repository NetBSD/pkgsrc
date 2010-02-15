# $NetBSD: Makefile,v 1.25 2010/02/15 16:32:20 joerg Exp $
#

DISTNAME=	rpy-0.99.0
PKGREVISION=	3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		YES

BUILDLINK_API_DEPENDS.R+= R>=2.7.0

BROKEN=		Doesn't support modern R.

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
