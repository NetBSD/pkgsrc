# $NetBSD: Makefile,v 1.6 2017/09/04 18:55:08 wiz Exp $

DISTNAME=	python-gflags-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://python-gflags.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/python-gflags
COMMENT=	Python equivalent of gflags, a commandline flag implementation
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 2.0

REPLACE_PYTHON+=	*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
