# $NetBSD: Makefile,v 1.3 2017/11/09 08:34:12 adam Exp $

DISTNAME=	PyExecJS-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/^py//}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyExecJS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/doloopwhile/PyExecJS
COMMENT=	Run JavaScript code from Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=		# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
