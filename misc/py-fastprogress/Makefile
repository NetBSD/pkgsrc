# $NetBSD: Makefile,v 1.4 2025/12/27 08:28:39 adam Exp $

DISTNAME=	fastprogress-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastprogress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AnswerDotAI/fastprogress
COMMENT=	Nested progress with plotting options for fastai
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
