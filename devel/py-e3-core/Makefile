# $NetBSD: Makefile,v 1.3 2025/09/24 05:36:17 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-22.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	e3-core

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/e3-core
COMMENT=	E3 core. Tools and library for building and testing software
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools

#DEPENDS+=	${PYPKGPREFIX}-bson-[0-9]*:../../wip/py-bson
# We will use mongodb instead, it includes bson
DEPENDS+=	${PYPKGPREFIX}-mongo-[0-9]*:../../databases/py-mongo
DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-cache-[0-9]*:../../devel/py-requests-cache
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt-[0-9]*:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-stevedore>=1.20.0:../../devel/py-stevedore
DEPENDS+=	${PYPKGPREFIX}-resolvelib-[0-9]*:../../devel/py-resolvelib
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-distro-[0-9]*:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock-[0-9]*:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-html-[0-9]*:../../devel/py-test-html
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket-[0-9]*:../../devel/py-test_socket
TEST_DEPENDS+=	${PYPKGPREFIX}-ansi2html-[0-9]*:../../converters/py-ansi2html
TEST_DEPENDS+=	${PYPKGPREFIX}-ptyprocess-[0-9]*:../../sysutils/py-ptyprocess

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"

pre-build:
	${RUN} cd ${WRKSRC} && \
	${CC} -o src/e3/os/data/rlimit-${MACHINE_ARCH}-${LOWER_OPSYS} tools/rlimit/rlimit.c

.endif

post-install:
.for bin in e3 e3-pypi-closure e3-sandbox
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"

.include "../../mk/bsd.pkg.mk"
