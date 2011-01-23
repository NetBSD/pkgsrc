# $NetBSD: Makefile,v 1.5 2011/01/23 22:16:30 tnn Exp $
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

DEPENDS+=	${PYPKGPREFIX}-darcsver:../../devel/py-darcsver-[0-9]*
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat-[0-9]*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
