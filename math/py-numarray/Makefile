# $NetBSD: Makefile,v 1.14 2008/04/25 20:39:10 joerg Exp $
#

DISTNAME=	numarray-1.5.2
PKGNAME=	${PYPKGPREFIX}-numarray-1.5.2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/numarray
COMMENT=	Array manipulation

PYDISTUTILSPKG=		yes

PLIST_VARS+=	blas
.if exists(/System/Library/Frameworks/vecLib.framework/Headers)
BUILDLINK_PASSTHRU_DIRS+=	/System/Library/Frameworks/vecLib.framework/Headers
PLIST.blas=	yes
.endif

do-test:
	(cd ${WRKSRC}/Lib && ${PYTHONBIN} testall.py)

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
