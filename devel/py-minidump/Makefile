#	$NetBSD: Makefile,v 1.1 2020/08/18 20:13:58 riastradh Exp $

DISTNAME=	minidump-0.0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/minidump/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/skelsec/minidump
COMMENT=	Python library to parse and read Microsoft minidump file format
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
