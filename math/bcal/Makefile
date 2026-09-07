# $NetBSD: Makefile,v 1.8 2026/09/07 21:44:14 sjmulder Exp $

DISTNAME=	bcal-2.6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jarun/bcal/
COMMENT=	Storage and general-purpose calculator
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# "Only 64-bit operating systems are supported." (README.md)
ONLY_FOR_PLATFORM=	${LP64PLATFORMS}

USE_TOOLS+=	gmake
MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
# No -O3 and -Werror
MAKE_FLAGS+=	CFLAGS_OPTIMIZATION=
MAKE_FLAGS+=	CFLAGS_WARNINGS="-Wall -Wextra -Wno-unused-parameter"

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} ./test.py

.include "options.mk"

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
