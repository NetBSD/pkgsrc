# $NetBSD: Makefile,v 1.1 2023/04/17 21:32:54 gutteridge Exp $

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

PKGCONFIG_OVERRIDE+=	liburing.pc.in

# Provides access to the Linux kernel io_uring interface
ONLY_FOR_PLATFORM=	Linux-*-*

do-build:
	${RUN} cd ${WRKSRC}/ && ./configure --prefix=${PREFIX} && ${GMAKE}

.include "../../mk/bsd.pkg.mk"
