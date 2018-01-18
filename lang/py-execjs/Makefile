# $NetBSD: Makefile,v 1.4 2018/01/18 10:13:27 adam Exp $

DISTNAME=	PyExecJS-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
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
