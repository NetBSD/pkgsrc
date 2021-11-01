# $NetBSD: Makefile,v 1.10 2021/11/01 21:05:56 wiz Exp $

DISTNAME=	markdown2social-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:M=/markdown2social/}
MASTER_SITES+=	${MASTER_SITE_GITHUB:=jmmv/markdown2social/releases/download/${DISTNAME}/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	https://github.com/jmmv/markdown2social/
COMMENT=	Converts simple Markdown documents to Google+ posts
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_VERSIONED_DEPENDENCIES+=	markdown

.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
