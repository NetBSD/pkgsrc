# $NetBSD: Makefile,v 1.2.18.1 2017/11/12 11:35:31 bsiegert Exp $

DISTNAME=	python-augeas-0.5.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PYPI:=python-augeas/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://augeas.net/
COMMENT=	Python bindings for Augeas
LICENSE=	gnu-lgpl-v2.1

EGG_NAME=       ${DISTNAME:S/-/_/}

do-test:
	(cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 test_augeas.py)

.include "../../sysutils/augeas/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
