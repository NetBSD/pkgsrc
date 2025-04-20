# $NetBSD: Makefile,v 1.8 2025/04/20 21:56:23 wiz Exp $

DISTNAME=	testpath-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testpath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter/testpath
COMMENT=	Test utilities for code working with files and commands
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core

USE_LANGUAGES=	# none

post-extract:
	${RM} ${WRKSRC}/testpath/cli-*.exe

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
