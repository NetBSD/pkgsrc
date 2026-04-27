# $NetBSD: Makefile,v 1.22 2026/04/27 10:22:49 wiz Exp $

DISTNAME=	hy-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.hylang.org/
COMMENT=	Lisp and Python love each other
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=1.0:../../devel/py-funcparserlib

USE_LANGUAGES=	# none

post-install:
.for bin in hy hy2py hyc
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

pre-test:
	${TOUCH} ${WRKSRC}/tests/__init__.py
	cd ${BUILDLINK_DIR}/bin && \
		${LN} -f -s ${PREFIX}/bin/hy-${PYVERSSUFFIX} hy && \
		${LN} -f -s ${PREFIX}/bin/hy2py-${PYVERSSUFFIX} hy2py && \
		${LN} -f -s ${PREFIX}/bin/hyc-${PYVERSSUFFIX} hyc

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
