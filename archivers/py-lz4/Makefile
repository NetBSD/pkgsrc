# $NetBSD: Makefile,v 1.1 2017/09/29 21:36:23 joerg Exp $

DISTNAME=	lz4-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lz4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-lz4/python-lz4
COMMENT=	Python LZ4 binding
LICENSE=	modified-bsd

.include "../../lang/python/distutils.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
