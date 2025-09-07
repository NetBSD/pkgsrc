# $NetBSD: Makefile,v 1.1 2025/09/07 18:33:59 maya Exp $

DISTNAME=	awscrt-0.27.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awscrt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/awscrt/
COMMENT=	Python 3 bindings for the AWS Common Runtime
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
