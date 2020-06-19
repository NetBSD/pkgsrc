# $NetBSD: Makefile,v 1.5 2020/06/19 18:04:05 gdt Exp $

VERSION=	3.0.0
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

# Note that the content which should be in NEWS (in plain text and
# thus insertable into pkgsrc commit messages) is instead at:
#   https://github.com/gavinhoward/bc/releases

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=		-G
CONFIGURE_ENV=		EXECSUFFIX="-gh" MANDIR="${PREFIX}/man" NLSPATH="${PREFIX}/share/locale/%L/%N"

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
