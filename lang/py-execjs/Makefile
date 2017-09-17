# $NetBSD: Makefile,v 1.2 2017/09/17 11:31:28 adam Exp $

DISTNAME=	PyExecJS-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
CATEGORIES=	python lang
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyExecJS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doloopwhile/PyExecJS
COMMENT=	Run JavaScript code from Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=		# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
