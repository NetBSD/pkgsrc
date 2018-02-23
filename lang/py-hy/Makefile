# $NetBSD: Makefile,v 1.8 2018/02/23 07:03:09 adam Exp $

DISTNAME=	hy-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hylang.org/
COMMENT=	Lisp and Python love each other
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-astor>=0.6:../../devel/py-astor
DEPENDS+=	${PYPKGPREFIX}-clint>=0.4:../../devel/py-clint
DEPENDS+=	${PYPKGPREFIX}-rply>=0.7.5:../../devel/py-rply

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${RM} hy[23] hy2py[23] hyc[23] && \
		${MV} hy hy${PYVERSSUFFIX} && \
		${MV} hy2py hy2py${PYVERSSUFFIX} && \
		${MV} hyc hyc${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
