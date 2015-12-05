# $NetBSD: Makefile,v 1.3 2015/12/05 21:25:37 adam Exp $

DISTNAME=	python-gflags-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://python-gflags.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/python-gflags/
COMMENT=	Python equivalent of gflags, a commandline flag implementation
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # as of 2.0

REPLACE_PYTHON+=	*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
