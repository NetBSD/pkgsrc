# $NetBSD: Makefile,v 1.2 2019/08/06 11:13:07 gdt Exp $

VERSION=	2.1.0
DISTNAME=	bc-${VERSION}
PKGNAME=	bc-gh-${VERSION}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=gavinhoward/}
GITHUB_PROJECT=	bc
GITHUB_RELEASE=	${VERSION}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	yzena.tech@gmail.com
HOMEPAGE=	https://github.com/gavinhoward/bc
COMMENT=	Implementation of POSIX bc with GNU extensions
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=		-G
CONFIGURE_ENV=		EXECSUFFIX="-gh" MANDIR="${PREFIX}/man" NLSPATH="${PREFIX}/share/locale/%L/%N"

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
