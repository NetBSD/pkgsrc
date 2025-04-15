# $NetBSD: Makefile,v 1.3 2025/04/15 15:43:15 adam Exp $

DISTNAME=	term-background-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	comms python
# No source distfile on PyPI
#MASTER_SITES=	${MASTER_SITE_PYPI:=t/term-background/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=rocky/}
GITHUB_PROJECT=	shell-term-background

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/shell-term-background
COMMENT=	Determine if shell has a light or dark background
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/shell-${DISTNAME}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
