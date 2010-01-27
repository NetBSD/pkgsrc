# $NetBSD: Makefile,v 1.1.1.1 2010/01/27 14:16:10 drochner Exp $
#

DISTNAME=	mpmath-0.13
PKGNAME=	${PYPKGPREFIX}-mpmath-0.13
CATEGORIES=	math
MASTER_SITES=	http://mpmath.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mpmath/
COMMENT=	Python library for arbitrary-precision FP arithmetic

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
