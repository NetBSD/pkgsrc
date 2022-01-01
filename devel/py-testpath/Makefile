# $NetBSD: Makefile,v 1.3 2022/01/01 16:14:50 ryoon Exp $

DISTNAME=	testpath-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testpath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter/testpath
COMMENT=	Test utilities for code working with files and commands
LICENSE=	mit

USE_LANGUAGES=	# none

post-extract:
	${RM} ${WRKSRC}/testpath/cli-*.exe

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
