# $NetBSD: Makefile,v 1.1 2022/08/31 08:23:29 sborrill Exp $

DISTNAME=	pathvalidate-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pathvalidate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pathvalidate
COMMENT=	Python library to sanitize/validate a string such as filenames

LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
