# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:06 wiz Exp $

DISTNAME=	flufl.testing-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flufl.testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/warsaw/flufl.testing/
COMMENT=	Small collection of test tool plugins
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
