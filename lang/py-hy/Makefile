# $NetBSD: Makefile,v 1.12 2022/11/26 19:53:38 adam Exp $

DISTNAME=	hy-0.25.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.hylang.org/
COMMENT=	Lisp and Python love each other
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-funcparserlib>=1.0:../../devel/py-funcparserlib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 39
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
