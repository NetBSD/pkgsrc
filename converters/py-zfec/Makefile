# $NetBSD: Makefile,v 1.1.1.1 2010/07/24 13:24:15 gdt Exp $
#

DISTNAME=	zfec-1.4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/z/zfec/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/packages/source/z/zfec/
COMMENT=	Fast erasure codec
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# Uses internal egg.
#DEPENDS+=	${PYPKGPREFIX}-darcsver:../../devel/py-darcsver

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
