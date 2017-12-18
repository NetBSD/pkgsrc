# $NetBSD: Makefile,v 1.7 2017/12/18 12:48:46 adam Exp $

DISTNAME=	hy-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hylang.org/
COMMENT=	Lisp and Python love each other
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-astor>=0.5:../../devel/py-astor
DEPENDS+=	${PYPKGPREFIX}-clint>=0.4:../../devel/py-clint
DEPENDS+=	${PYPKGPREFIX}-rply>=0.7.0:../../devel/py-rply

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${RM} hy[23] hy2py[23] hyc[23] && \
		${MV} hy hy${PYVERSSUFFIX} && \
		${MV} hy2py hy2py${PYVERSSUFFIX} && \
		${MV} hyc hyc${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
