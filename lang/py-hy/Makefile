# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:34 wiz Exp $

DISTNAME=	hy-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hy/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://hylang.org/
COMMENT=	Lisp and Python love each other
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-rply>=0.7.0:../../devel/py-rply
DEPENDS+=	${PYPKGPREFIX}-astor>=0.3:../../devel/py-astor

USE_LANGUAGES=	# none

PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/hy \
		${DESTDIR}${PREFIX}/bin/hy${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/hy2py \
		${DESTDIR}${PREFIX}/bin/hy2py${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/hyc \
		${DESTDIR}${PREFIX}/bin/hyc${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
