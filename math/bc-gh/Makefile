# $NetBSD: Makefile,v 1.8 2020/07/10 00:01:29 gdt Exp $

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

# Note that the content which should be in NEWS (in plain text and
# thus insertable into pkgsrc commit messages) is instead at:
#   https://github.com/gavinhoward/bc/releases

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.sh
# -l means install all translations, not examining local locales
CONFIGURE_ARGS=		-G -l
CONFIGURE_ENV=		EXECSUFFIX="-gh" MANDIR="${PREFIX}/${PKGMANDIR}" NLSPATH="${PREFIX}/share/locale/%L/%N"

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
