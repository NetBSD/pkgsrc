# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:37 joerg Exp $
#

DISTNAME=	numarray-1.5.2
PKGNAME=	${PYPKGPREFIX}-numarray-1.5.2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/numarray
COMMENT=	Array manipulation

PKG_DESTDIR_SUPPORT=	user-destdir

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
