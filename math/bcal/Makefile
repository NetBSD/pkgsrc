# $NetBSD: Makefile,v 1.6 2022/01/29 14:55:08 sjmulder Exp $

DISTNAME=	bcal-2.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jarun/bcal/
COMMENT=	Storage and general-purpose calculator
LICENSE=	gnu-gpl-v3

# "Only 64-bit operating systems are supported." (README.md)
ONLY_FOR_PLATFORM=	${LP64PLATFORMS}

USE_TOOLS+=	gmake
DEPENDS+=	bc-[0-9]*:../../math/bc
MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
# No -O3 and -Werror
MAKE_FLAGS+=	CFLAGS_OPTIMIZATION=
MAKE_FLAGS+=	CFLAGS_WARNINGS="-Wall -Wextra -Wno-unused-parameter"

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
