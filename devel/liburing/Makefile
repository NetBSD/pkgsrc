# $NetBSD: Makefile,v 1.2 2023/07/19 15:20:48 nia Exp $

DISTNAME=	liburing-2.3
CATEGORIES=	devel
MASTER_SITES=	https://git.kernel.dk/cgit/liburing/snapshot/

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

do-build:
	${RUN} cd ${WRKSRC}/ && ./configure --prefix=${PREFIX} && ${GMAKE}

.include "../../mk/bsd.pkg.mk"
