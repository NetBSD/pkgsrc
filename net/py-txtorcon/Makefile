# $NetBSD: Makefile,v 1.2 2019/02/28 06:31:57 wiz Exp $

DISTNAME=	txtorcon-19.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=meejah/}
GITHUB_PROJECT=	txtorcon
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://txtorcon.readthedocs.io/
COMMENT=	Twisted Python library for controlling tor daemon
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.1:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-automat-[0-9]*:../../devel/py-automat
DEPENDS+=	${PYPKGPREFIX}-incremental-[0-9]*:../../devel/py-incremental
.if ${_PYTHON_VERSION} < 33
DEPENDS+=	${PYPKGPREFIX}-ipaddress>=1.0.16:../../net/py-ipaddress
.endif
DEPENDS+=	${PYPKGPREFIX}-twisted>=15.5.0:../../net/py-twisted

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

CHECK_INTERPRETER_SKIP+=	share/txtorcon/examples/*

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
