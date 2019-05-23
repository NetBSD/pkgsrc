# $NetBSD: Makefile,v 1.4 2019/05/23 19:22:59 rillig Exp $

DISTNAME=	jupyter_core-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter_core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org/
COMMENT=	Jupyter core package
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.1.0:../../devel/py-traitlets
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fixing prefix.
SUBST_FILES.fix-prefix=		jupyter_core/paths.py
SUBST_VARS.fix-prefix=		PREFIX

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter jupyter${PYVERSSUFFIX} && \
	${MV} jupyter-migrate jupyter-migrate${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/jupyter_core && py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
