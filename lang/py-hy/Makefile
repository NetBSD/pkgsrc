# $NetBSD: Makefile,v 1.14 2023/03/29 09:34:11 wiz Exp $

DISTNAME=	hy-0.25.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.hylang.org/
COMMENT=	Lisp and Python love each other
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=1.0:../../devel/py-funcparserlib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-astor>=0.8:../../devel/py-astor
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${RM} hy[23] hy2py[23] hyc[23] && \
		${MV} hy hy-${PYVERSSUFFIX} && \
		${MV} hy2py hy2py-${PYVERSSUFFIX} && \
		${MV} hyc hyc-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
