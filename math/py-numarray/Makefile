# $NetBSD: Makefile,v 1.11 2006/03/08 17:21:34 minskim Exp $
#

DISTNAME=	numarray-1.5.1
PKGNAME=	${PYPKGPREFIX}-numarray-1.5.1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/numarray
COMMENT=	Array manipulation

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22

.if exists(/System/Library/Frameworks/vecLib.framework/Headers)
BUILDLINK_PASSTHRU_DIRS+=	/System/Library/Frameworks/vecLib.framework/Headers
PLIST_SUBST+=	DOTBLAS=""
.else
PLIST_SUBST+=	DOTBLAS="@comment "
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
