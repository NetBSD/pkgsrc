# $NetBSD: Makefile,v 1.3 2005/01/23 20:41:48 recht Exp $
#

DISTNAME=	numarray-1.0
PKGNAME=	${PYPKGPREFIX}-numarray-1.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/numarray
COMMENT=	Array manipulation

USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
