# $NetBSD: Makefile,v 1.2 2022/01/17 18:38:23 rhialto Exp $

DISTNAME=	unrardll-0.1.5
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
