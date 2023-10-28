# $NetBSD: Makefile,v 1.7 2023/10/28 19:57:08 wiz Exp $

DISTNAME=	unpaddedbase64-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_PROJECT=	python-unpaddedbase64
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/matrix-org/python-unpaddedbase64
COMMENT=	Encode and decode Base64 without "=" padding
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-poetry-core

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/python-${DISTNAME}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
