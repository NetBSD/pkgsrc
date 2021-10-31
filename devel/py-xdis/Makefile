# $NetBSD: Makefile,v 1.36 2021/10/31 08:40:03 adam Exp $

DISTNAME=	xdis-6.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xdis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-xdis
COMMENT=	Python cross-version byte-code disassembler and marshal routines
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pydisasm pydisasm-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
