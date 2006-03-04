# $NetBSD: Makefile,v 1.14 2006/03/04 21:30:08 jlam Exp $
#

DISTNAME=	rpy-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	math python
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=       http://rpy.sourceforge.net/
COMMENT=	R interface for Python

PYDISTUTILSPKG=		YES

BUILDLINK_DEPENDS.R+= R>=2.2.1

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
