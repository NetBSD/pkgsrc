# $NetBSD: Makefile,v 1.23 2008/06/12 02:14:37 joerg Exp $
#

DISTNAME=	rpy-0.99.0
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rpy.sourceforge.net/
COMMENT=	R interface for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		YES

BUILDLINK_API_DEPENDS.R+= R>=2.7.0

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
