# $NetBSD: Makefile,v 1.4 2005/02/09 12:16:02 markd Exp $
#

DISTNAME=	numarray-1.1.1
PKGNAME=	${PYPKGPREFIX}-numarray-1.1.1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/numarray
COMMENT=	Array manipulation

USE_BUILDLINK3=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
