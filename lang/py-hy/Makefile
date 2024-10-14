# $NetBSD: Makefile,v 1.16 2024/10/14 06:08:40 wiz Exp $

DISTNAME=	hy-0.29.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.hylang.org/
COMMENT=	Lisp and Python love each other
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=1.0:../../devel/py-funcparserlib

USE_LANGUAGES=	# none

post-install:
.for bin in hy hy2py hyc
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
