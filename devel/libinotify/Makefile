# $NetBSD: Makefile,v 1.13 2024/08/06 12:38:50 wiz Exp $

DISTNAME=	libinotify
PKGNAME=	${DISTNAME}-0.0.${GITHUB_TAG}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libinotify-kqueue/}
GITHUB_PROJECT=	libinotify-kqueue
GITHUB_TAG=	20240724

MAINTAINER=	me@dmitrymatveev.co.uk
#HOMEPAGE=	http://dmitrymatveev.co.uk/gsoc11
COMMENT=	Inotify emulation library for *BSDs
LICENSE=	mit

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++17
USE_TOOLS+=	autoconf automake autoreconf

.include "../../mk/compiler.mk"

# Avoid error due to use of ATOMIC_VAR_INIT.
.if ${CC_VERSION:Mclang-1[5-9].*}
CFLAGS+=	-Wno-deprecated-pragma
.endif

TEST_TARGET=	test

NOT_FOR_PLATFORM+=	SunOS-*-* Linux-*-*

pre-configure:
	cd ${WRKSRC} && autoreconf -fvi

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
