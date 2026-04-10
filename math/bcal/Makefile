# $NetBSD: Makefile,v 1.7 2026/04/10 20:35:17 sjmulder Exp $

DISTNAME=	bcal-2.5
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

.include "../../lang/python/pyversion.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
