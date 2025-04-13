# $NetBSD: Makefile,v 1.18 2025/04/13 07:22:37 adam Exp $

DISTNAME=	emoji-2.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/emoji/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/carpedm20/emoji
COMMENT=	ASCII<->Emoji conversion library for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
