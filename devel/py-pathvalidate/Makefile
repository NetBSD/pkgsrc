# $NetBSD: Makefile,v 1.2 2022/08/31 09:36:03 adam Exp $

DISTNAME=	pathvalidate-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pathvalidate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thombashi/pathvalidate
COMMENT=	Python library to sanitize/validate a string such as filenames
LICENSE=	mit

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
