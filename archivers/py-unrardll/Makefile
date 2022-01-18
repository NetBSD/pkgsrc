# $NetBSD: Makefile,v 1.3 2022/01/18 20:59:04 rhialto Exp $

DISTNAME=	unrardll-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unrardll/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kovidgoyal/unrardll
COMMENT=	Python bindings for libunrar
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++

.include "../../lang/python/egg.mk"
.include "../../archivers/libunrar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
