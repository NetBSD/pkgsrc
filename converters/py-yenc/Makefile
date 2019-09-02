# $NetBSD: Makefile,v 1.7 2019/09/02 13:19:58 adam Exp $

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

PYTHON_VERSIONS_ACCEPTED=	 27 # as of 0.4.0

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
