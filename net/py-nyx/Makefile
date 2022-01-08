# $NetBSD: Makefile,v 1.4 2022/01/08 12:11:51 wiz Exp $

.include "../../net/py-nyx/Makefile.common"

DISTNAME=	nyx-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nyx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nyx.torproject.org/
COMMENT=	Command-line monitor for the tor daemon
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-stem>=1.7.0:../../devel/py-stem

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	run_nyx
REPLACE_PYTHON+=	run_tests.py
REPLACE_PYTHON+=	setup.py

do-test:
	cd ${WRKSRC} && ./run_tests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
