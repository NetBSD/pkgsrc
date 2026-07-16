# $NetBSD: Makefile,v 1.7 2026/07/16 09:13:18 adam Exp $

DISTNAME=	awscrt-0.35.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awscrt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/awslabs/aws-crt-python
COMMENT=	Python 3 bindings for the AWS Common Runtime
LICENSE=	apache-2.0

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
