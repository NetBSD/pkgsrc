# $NetBSD: Makefile,v 1.4 2026/05/06 19:17:19 vins Exp $

DISTNAME=	liburing-2.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=axboe/}
GITHUB_TAG=	${PKGBASE}-${PKGVERSION_NOREV}

MAINTAINER=	als@thangorodrim.ch
HOMEPAGE=	https://git.kernel.dk/cgit/liburing/
COMMENT=	Library for the Linux kernel io_uring interface
LICENSE=	gnu-gpl-v2

# The ./configure in the source is a handcrafted piece of shell
HAS_CONFIGURE=	YES

USE_TOOLS+=	gmake

USE_LANGUAGES=	c c++

# Uses stdatomic.
USE_CC_FEATURES+=	c11

PKGCONFIG_OVERRIDE+=	liburing.pc.in

# Provides access to the Linux kernel io_uring interface
ONLY_FOR_PLATFORM=	Linux-*-*

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--mandir=${PREFIX}/${PKGMANDIR}

# Do not hard-code compiler
CONFIGURE_ARGS+=	--cc=${CC:Q} \
			--cxx=${CXX:Q}

TEST_TARGET=		runtests

.include "../../mk/bsd.pkg.mk"
