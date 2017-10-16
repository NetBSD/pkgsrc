# $NetBSD: Makefile,v 1.2 2017/10/16 17:14:10 adam Exp $

DISTNAME=	testpath-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testpath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter/testpath
COMMENT=	Test utilities for code working with files and commands
LICENSE=	mit

USE_LANGUAGES=	# none

post-extract:
	${RM} ${WRKSRC}/testpath/cli-*.exe

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
