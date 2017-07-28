# $NetBSD: Makefile,v 1.1 2017/07/28 07:01:31 adam Exp $

DISTNAME=	PyExecJS-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
CATEGORIES=	python lang
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyExecJS/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doloopwhile/PyExecJS
COMMENT=	Run JavaScript code from Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=		# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
