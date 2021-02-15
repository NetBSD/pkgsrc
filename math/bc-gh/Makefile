# $NetBSD: Makefile,v 1.9 2021/02/15 01:07:24 gdt Exp $

VERSION=	3.1.2
DISTNAME=	bc-${VERSION}
PKGNAME=	bc-gh-${VERSION}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=gavinhoward/}
GITHUB_PROJECT=	bc
GITHUB_RELEASE=	${VERSION}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	yzena.tech@gmail.com
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/gavinhoward/bc
COMMENT=	Implementation of POSIX bc with GNU extensions
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.sh
# -l means install all translations, not examining local locales
CONFIGURE_ARGS=		-G -l
CONFIGURE_ENV=		EXECSUFFIX="-gh" MANDIR="${PREFIX}/${PKGMANDIR}" NLSPATH="${PREFIX}/share/locale/%L/%N"

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
