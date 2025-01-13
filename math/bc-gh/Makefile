# $NetBSD: Makefile,v 1.12 2025/01/13 14:31:56 ktnb Exp $

VERSION=	7.0.3
DISTNAME=	bc-${VERSION}
PKGNAME=	bc-gh-${VERSION}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=gavinhoward/}
GITHUB_PROJECT=	bc
GITHUB_RELEASE=	${VERSION}

MAINTAINER=	yzena.tech@gmail.com
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/gavinhoward/bc
COMMENT=	Implementation of POSIX bc with GNU extensions
LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.sh
# -l means install all translations, not examining local locales
CONFIGURE_ARGS=		-G -l
CONFIGURE_ENV=		EXECSUFFIX="-gh" MANDIR="${PREFIX}/${PKGMANDIR}" NLSPATH="${PREFIX}/share/locale/%L/%N"

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
