# $NetBSD: Makefile,v 1.12 2006/01/27 21:50:41 markd Exp $
#

DISTNAME=	rpy-0.4.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=rpy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=       http://rpy.sourceforge.net/
COMMENT=	R interface for Python

PYDISTUTILSPKG=		YES

BUILDLINK_DEPENDS.R+= R>=2.2.1

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/R/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
