# $NetBSD: Makefile,v 1.4 2025/10/20 07:59:44 adam Exp $

DISTNAME=	invoke-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/invoke/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyinvoke.org/
COMMENT=	Pythonic task execution
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
.for bin in inv invoke
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
