# $NetBSD: Makefile,v 1.5 2023/03/29 09:34:05 wiz Exp $

DISTNAME=	absl-py-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/absl-py/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-py
COMMENT=	Abseil Python Common Libraries
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
