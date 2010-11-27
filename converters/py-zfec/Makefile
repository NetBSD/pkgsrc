# $NetBSD: Makefile,v 1.4 2010/11/27 14:04:39 gdt Exp $
#

DISTNAME=	zfec-1.4.7
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://pypi.python.org/packages/source/z/zfec/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/packages/source/z/zfec/
COMMENT=	Fast erasure codec
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-darcsver:../../devel/py-darcsver
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
