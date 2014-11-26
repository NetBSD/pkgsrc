# $NetBSD: Makefile,v 1.1 2014/11/26 15:01:12 wiz Exp $

DISTNAME=	python-gflags-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	http://python-gflags.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/python-gflags/
COMMENT=	Python equivalent of gflags, a commandline flag implementation
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # as of 2.0

EGG_NAME=		${DISTNAME:S/-/_/}

REPLACE_PYTHON+=	*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
