# $NetBSD: Makefile,v 1.3 2019/06/12 20:57:07 sjmulder Exp $

DISTNAME=	bcal-2.1
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

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
