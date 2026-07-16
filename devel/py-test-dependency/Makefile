# $NetBSD: Makefile,v 1.1 2026/07/16 19:27:05 wiz Exp $

DISTNAME=	pytest_dependency-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_dependency/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/RKrahl/pytest-dependency
COMMENT=	Manage dependencies of tests
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
