# $NetBSD: Makefile,v 1.5 2018/07/03 05:03:05 adam Exp $

DISTNAME=	yenc-${DISTVERSION}
DISTVERSION=	0.4.0

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
REPLACE_PYTHON=	*.py
CATEGORIES=	devel
MASTER_SITES=	http://www.golug.it/pub/yenc/

PYDISTUTILSPKG=	yes

MAINTAINER=	pkgsrc128@fastmail.us
HOMEPAGE=	http://www.golug.it/yenc.html
COMMENT=	Python module for yenc decoding module in C
LICENSE=        gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.4.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
