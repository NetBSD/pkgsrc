# $NetBSD: Makefile,v 1.5 2022/01/04 20:54:08 wiz Exp $

DISTNAME=	PyExecJS-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyExecJS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doloopwhile/PyExecJS
COMMENT=	Run JavaScript code from Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
