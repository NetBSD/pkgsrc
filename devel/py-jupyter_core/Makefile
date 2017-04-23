# $NetBSD: Makefile,v 1.1 2017/04/23 04:23:52 markd Exp $

DISTNAME=	jupyter_core-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org
COMMENT=	Jupyter core package
LICENSE=	modified-bsd

DEPENDS+=       ${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jupyter ${DESTDIR}${PREFIX}/bin/jupyter${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/jupyter-migrate ${DESTDIR}${PREFIX}/bin/jupyter-migrate${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
